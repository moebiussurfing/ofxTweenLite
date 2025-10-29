# TODO

##----

## DONE. CHANGELOG

- no tocar ofxTweenLite, ya que la classe main no es hecha por mi
- mejorar ofxTweenLiteHelper
- mejora ejemplo example4 ofapp

## ofxTweenLiteHelper

- revisa y dime si efectivamente como quiero ofxTweenLiteHelper.h solo maneja un tweener a la vez. es lo que quiero.
- revisa si puede simplificarse o mejorarse de alguna forma:
    - revisa que no sea propenso a errores de memoria o crashes.
    - quiero que haya algunos params internos de ajuste para el tween.
    - las variables a tqeenear por ahora son float, int, ofcolor y vec2. por ahora con estas en T tengo suficiente.
- anadir ofparameter int (tween type index) y y param string (nombre del tween sacado facil de la clase) para usar en ofxGui ofxPanel para poder ser cambiados via gui.
- anade ofparam void para disparar el tween start. recuerda siempre callbacks lambda. (params: start, stop, pause)
- graba estos params como settings json.
- el ofxPanel lo quiero en ofApp (no en ofxTweenLiteHelper), solo los ofparams y settings json en un ofparamgroup en ofxTweenLiteHelper

## HOW TO?

- hazme propuestas antes de implementar