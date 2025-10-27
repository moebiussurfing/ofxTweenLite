//
// ofxTweenLiteHelper.h
//
// Helper class created by moebiusSurfing
// for the ofxTweenLite.h originally by lukasz karluk.
//

#pragma once
#include "ofMain.h"
#include "ofxTweenLite.h"
#include <functional>
#include <glm/glm.hpp>
#include <string>
#include <type_traits>
#include <vector>

// Helper for interpolation
namespace ofxTweenLiteHelperUtils {
	template <typename T>
	inline T lerp(const T & a, const T & b, float t) { return a + (b - a) * t; }
	template <>
	inline glm::vec2 lerp(const glm::vec2 & a, const glm::vec2 & b, float t) { return a + (b - a) * t; }
	template <>
	inline ofColor lerp(const ofColor & a, const ofColor & b, float t) {
		return ofColor(
			ofLerp(a.r, b.r, t),
			ofLerp(a.g, b.g, t),
			ofLerp(a.b, b.b, t),
			ofLerp(a.a, b.a, t));
		}
	}
	
	// Main helper class
	template <typename T>
	class ofxTweenLiteHelper {
		public:
		ofxTweenLiteHelper()
		: from(T {})
		, to(T {})
		, value(T {})
		, initialFrom(T {})
		, duration(1.0f)
		, easeMode(OF_EASE_LINEAR_IN)
		, startTime(0.0f)
		, pauseTime(0.0f)
		, finished(true)
		, paused(false)
		, chainFromCurrentValue(false)
		, repeatCount(0)
		, currentRepeat(0)
		, onStart(nullptr)
		, onUpdate(nullptr)
		, onComplete(nullptr)
		, onCancel(nullptr) { }

		// Fluent API
		ofxTweenLiteHelper & setFrom(const T & v) {
			from = v;
			initialFrom = v; // remember the configured start value
			return *this;
		}
		ofxTweenLiteHelper & setTo(const T & v) {
			to = v;
			return *this;
		}
		ofxTweenLiteHelper & setDuration(float d) {
			duration = d;
			return *this;
		}
		ofxTweenLiteHelper & setEase(ofEaseFunction e) {
			easeMode = e;
			return *this;
		}
		ofxTweenLiteHelper & setRepeat(int count) {
			repeatCount = count;
			return *this;
		}
		ofxTweenLiteHelper & setChainFromCurrentValue(bool chain) {
			chainFromCurrentValue = chain;
			return *this;
		}
		ofxTweenLiteHelper & onStartCallback(std::function<void()> cb) {
			onStart = cb;
			return *this;
		}
		ofxTweenLiteHelper & onUpdateCallback(std::function<void()> cb) {
			onUpdate = cb;
			return *this;
		}
		ofxTweenLiteHelper & onCompleteCallback(std::function<void()> cb) {
			onComplete = cb;
			return *this;
		}
		ofxTweenLiteHelper & onCancelCallback(std::function<void()> cb) {
			onCancel = cb;
			return *this;
		}
		
		// Starts the tween for a value
		void start(const T & from_, const T & to_, float duration_, ofEaseFunction easeMode_ = OF_EASE_LINEAR_IN, std::function<void()> onComplete_ = nullptr) {
			// When called explicitly by user, update initialFrom as well
			startInternal(from_, to_, duration_, easeMode_, onComplete_, true);
		}
		
		// Starts the tween using previously set parameters
		void start() {
			// If tween is currently running, honor chainFromCurrentValue: start from current value if chain enabled,
			// otherwise start from the original initialFrom.
			if (isRunning()) {
				if (chainFromCurrentValue) {
					startInternal(value, to, duration, easeMode, onComplete, false);
				} else {
					startInternal(initialFrom, to, duration, easeMode, onComplete, false);
				}
			} else {
				// If tween is stopped (not running), always start from the original initialFrom regardless of chain flag
				startInternal(initialFrom, to, duration, easeMode, onComplete, false);
			}
		}
		
		// Cancels the tween
		void cancel() {
			finished = true;
			if (onCancel) onCancel();
		}
		
		// Pauses the tween
		void pause() {
			paused = true;
			pauseTime = ofGetElapsedTimef();
		}
		
		// Resumes the tween
		void resume() {
			if (paused) {
				float pausedDuration = ofGetElapsedTimef() - pauseTime;
				startTime += pausedDuration;
				paused = false;
			}
		}
		
		// Updates the tween and calculates the value
		void update() {
			if (paused) {
				// When paused, don't update but keep current value
				return;
			}
			if (finished) {
				// When finished, keep the final calculated value, don't force it to 'to'
				return;
			}
			float elapsed = ofGetElapsedTimef() - startTime;
			float progress = ofClamp(elapsed / duration, 0.0f, 1.0f);
			value = ofxTweenLiteHelperUtils::lerp(from, to, ofxTweenLite::tween(0.0f, 1.0f, progress, easeMode));
			if (onUpdate) onUpdate();
			if (progress >= 1.0f && !finished) {
				// Set value to exact 'to' when completing
				value = to;
				currentRepeat++;
				if (repeatCount > 0 && currentRepeat < repeatCount) {
					// Loop: when looping we consider the chainFromCurrentValue flag as well
					// Use startInternal with updateInitialFrom=false to preserve original start value
					if (chainFromCurrentValue) {
						startInternal(value, to, duration, easeMode, onComplete, false);
					} else {
						startInternal(initialFrom, to, duration, easeMode, onComplete, false);
					}
				} else {
					finished = true;
					if (onComplete) onComplete();
				}
			}
		}
		
		// Returns the current tweened value
		T getValue() const {
			return value;
		}
		
		// Returns normalized progress (0 to1)
		float getProgress() {
			if (finished) return 1.0f;
			float elapsed = ofGetElapsedTimef() - startTime;
			float progress = ofClamp(elapsed / duration, 0.0f, 1.0f);
			return progress;
		}
		
		// Check if finished
		bool isFinished() const {
			return finished;
		}
		bool isPaused() const {
			return paused;
		}
		bool isRunning() const {
			return !finished && !paused;
		}
		bool getChainFromCurrentValue() const {
			return chainFromCurrentValue;
		}
		
		// Static: get all ease modes
		static const std::vector<ofEaseFunction> & getAllEaseModes() {
			static std::vector<ofEaseFunction> modes = {
				OF_EASE_BACK_IN, OF_EASE_BACK_OUT, OF_EASE_BACK_INOUT,
				OF_EASE_BOUNCE_IN, OF_EASE_BOUNCE_OUT, OF_EASE_BOUNCE_INOUT,
				OF_EASE_CIRC_IN, OF_EASE_CIRC_OUT, OF_EASE_CIRC_INOUT,
				OF_EASE_CUBIC_IN, OF_EASE_CUBIC_OUT, OF_EASE_CUBIC_INOUT,
				OF_EASE_ELASTIC_IN, OF_EASE_ELASTIC_OUT, OF_EASE_ELASTIC_INOUT,
				OF_EASE_EXPO_IN, OF_EASE_EXPO_OUT, OF_EASE_EXPO_INOUT,
				OF_EASE_LINEAR_IN, OF_EASE_LINEAR_OUT, OF_EASE_LINEAR_INOUT,
				OF_EASE_QUAD_IN, OF_EASE_QUAD_OUT, OF_EASE_QUAD_INOUT,
				OF_EASE_QUART_IN, OF_EASE_QUART_OUT, OF_EASE_QUART_INOUT,
				OF_EASE_QUINT_IN, OF_EASE_QUINT_OUT, OF_EASE_QUINT_INOUT,
				OF_EASE_SINE_IN, OF_EASE_SINE_OUT, OF_EASE_SINE_INOUT
			};
			return modes;
		}
		
		// Static: get all ease names
		static const std::vector<std::string> & getAllEaseNames() {
			static std::vector<std::string> names = {
				"BackIn", "BackOut", "BackInOut",
				"BounceIn", "BounceOut", "BounceInOut",
				"CircIn", "CircOut", "CircInOut",
				"CubicIn", "CubicOut", "CubicInOut",
				"ElasticIn", "ElasticOut", "ElasticInOut",
				"ExpoIn", "ExpoOut", "ExpoInOut",
				"LinearIn", "LinearOut", "LinearInOut",
				"QuadIn", "QuadOut", "QuadInOut",
				"QuartIn", "QuartOut", "QuartInOut",
				"QuintIn", "QuintOut", "QuintInOut",
				"SineIn", "SineOut", "SineInOut"
			};
			return names;
		}
		
		private:
		T from, to, value;
		T initialFrom; // store the configured initial 'from' value so toggling chain doesn't change stopped tweens
		float duration;
		ofEaseFunction easeMode;
		float startTime;
		float pauseTime;
		bool finished;
		bool paused;
		bool chainFromCurrentValue;
		int repeatCount;
		int currentRepeat;
		std::function<void()> onStart;
		std::function<void()> onUpdate;
		std::function<void()> onComplete;
		std::function<void()> onCancel;
		
		// Internal start method that optionally updates initialFrom
		void startInternal(const T & from_, const T & to_, float duration_, ofEaseFunction easeMode_, std::function<void()> onComplete_, bool updateInitialFrom) {
			from = from_;
			if (updateInitialFrom) {
				initialFrom = from_;
			}
			to = to_;
			duration = duration_;
			easeMode = easeMode_;
			startTime = ofGetElapsedTimef();
			finished = false;
			paused = false;
			currentRepeat = 0;
			onComplete = onComplete_;
			value = from;
			if (onStart) onStart();
		}
	};
