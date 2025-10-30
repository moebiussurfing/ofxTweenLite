# TODO

## ofxTweenLiteHelper

- he hecho cambios en ofxTweenLiteHelper para poder manejar mas automaticamente settings y setup en ofapp por el coder.
- mejorar ofxTweenLiteHelper
- mejorar ejemplo /example4 ofapp (current project)
- implementar pRepeatCount_ en ofxTweenLiteHelper
- implementar el callback en el lugar exacto de ofxTweenLiteHelper, para que no sea necesario hacerlo desde ofApp. ha de revisar que se haga mientras isRunning! ya que casi siempre leeremos el valor del tween solo cuando isRunning!
//ofApp.cpp
//TODO: this should be handled correctly inside ofxTweenLiteHelper!
// // Setup callback to ensure exact final value
// tweenRadius.onCompleteCallback([this]() {
// 	valueParamTweened.set(1.0f); // Force exact final value when tween completes
// 	ofLogNotice("ofApp") << "Tween completed - set to 1.0f. tweenRadius value: " << tweenRadius.getValue();
// });
- implementar 'Refresh GUI to minimize' detallado en setupGui() TODO lines!

## DUDAS. PREGUNTAS:
- es posible tal como esta redefinir la funcion que se corre al terminar el tween complete? porque quizas me gustaria tener la posibilidad de ir sobreescribiendo la funcion para establecer como un workflow o state machine para el uso de mi app. ten en cuenta que el callback interno de complete, deberia ser independiente, ya que es un workaround para garantizar que, debido a los diferentes posibles fps, el tween llegue el destino (end value), cuando se considera tween completado.

## HOWTO. RULES:
- hazme propuestas antes de implementar.
- no tocar ofxTweenLite, ya que la classe main no es hecha por mi y quiero mantener la dependencia intacta.

## ----------

# DONE: CHANGELOG:

- revisa y dime si efectivamente como quiero ofxTweenLiteHelper.h solo maneja un tweener a la vez. es lo que quiero.
- revisa si puede simplificarse o mejorarse de alguna forma:
    - revisa que no sea propenso a errores de memoria o crashes.
    - quiero que haya algunos params internos de ajuste para el tween.
    - las variables a tweenear por ahora son float, int, ofcolor y vec2. por ahora con estas en T tengo suficiente.
- anadir ofparameter int (tween type index) y y param string (nombre del tween sacado facil de la clase) para usar en ofxGui ofxPanel para poder ser cambiados via gui.
- anade ofparam void para disparar el tween start. recuerda siempre callbacks lambda. (params: start, stop, pause)
- graba estos params como settings json.
- el ofxPanel lo quiero en ofApp (no en ofxTweenLiteHelper), solo los ofparams y settings json en un ofparamgroup en ofxTweenLiteHelper