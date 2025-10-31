# TODO

## DO NOW:

- `stop` debe resetear value a `from` y `progress` a 0
- aplica valor directamente al ofParam


## HOWTO: RULES:

- preguntame tus dudas antes de empezar o implementar
- hazme propuestas antes de implementar
- no tocar ofxTweenLite, ya que la classe main no es hecha por mi y quiero mantener la dependencia intacta
- no toques mis lineas conectadas
- no cambies cosas sin pedirme autorizacion, por favor
- usa build Debug siempre, nunca Release

## ----------

## IGNORE: Future Ideas

- Add animation sequences/timelines

## ----------

# DONE: CHANGELOG:

## October 30, 2025 - Session 2

✅ **pFrom_ and pTo_ parameters** - Added ofParameter<T> for `from` and `to` values
  - Exposed in GUI and serialized to JSON
  - Automatically synced when using setFrom() and setTo() methods
  - Updated in ensureDefaultRangeIfUnset_() for default 0..1 range
✅ **stop() method** - Properly implemented to reset tween to initial state
  - Resets value to initialFrom
  - Resets currentRepeat counter to 0
  - Sets finished=true and paused=false
  - Triggers onCancel callback
  - cancel() now calls stop() as an alias
✅ **Final value clamping verification** - Confirmed working correctly
  - Line 248: `value = to;` ensures exact final value before marking as finished
  - Workaround for FPS variations already implemented and working

## October 30, 2025 - Session 1

✅ **Automatic onComplete callback** - Already implemented in update() method to force exact final value
✅ **Repeat count** - Already fully implemented with pRepeatCount_ parameter
✅ **refreshGui() method** - Added to automatically minimize Advanced parameters group
✅ **User-level callback system** - Added onUserCompleteCallback() separate from internal callback
  - Internal callback: Forces exact final value (workaround for FPS variations)
  - User callback: Runs after internal callback for state machine/workflow control
  - User can redefine callback anytime with .onUserCompleteCallback()
✅ **Cleaned up ofApp.cpp** - Removed TODO comments and implemented new features
✅ **Example implementation** - Added example of user callback usage in example4

## Previous Work

- revisa y dime si efectivamente como quiero ofxTweenLiteHelper.h solo maneja un tweener a la vez. es lo que quiero.
- revisa si puede simplificarse o mejorarse de alguna forma:
    - revisa que no sea propenso a errores de memoria o crashes.
    - quiero que haya algunos params internos de ajuste para el tween.
    - las variables a tweenear por ahora son float, int, ofcolor y vec2. por ahora con estas en T tengo suficiente.
- anadir ofparameter int (tween type index) y y param string (nombre del tween sacado facil de la clase) para usar en ofxGui ofxPanel para poder ser cambiados via gui.
- anade ofparam void para disparar el tween start. recuerda siempre callbacks lambda. (params: start, stop, pause)
- graba estos params como settings json.
- el ofxPanel lo quiero en ofApp (no en ofxTweenLiteHelper), solo los ofparams y settings json en un ofparamgroup en ofxTweenLiteHelper