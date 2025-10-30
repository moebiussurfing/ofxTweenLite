# TODO

## DO NOW:

- quiero recuperar o anadir los params `from` y `to`. (no hacen falta listeners aqui)
- para `onUserCompleteCallback` quiero un tipo de `fuction` cpp que se pueda pasar como argumento. es mas, quiero que pueda cambiar esta funcion durante el runtime... es posible? asi es como hare mi maquina de estados
- implementa `resume`, ahora funciona el pause pero no resume
- el `stop` tampoco esta implementado: debe poner el progress y value a 0 (o start `from` value)
- implementar el `repeat` counter.
- repasa que al final del tween no se esta clavando al valor final o valor `to`! cada vez que lo corro cambia el valor final: en este caso 199.98, 200.12 etc. Recuerda: quiero que internamente `ofxTweenLite`, antes de marcar el objeto como isRunning = false, ponga el valor del tween al valor final, ya que los fps hacen que pueda no llegar el valor final el tween value y progress. No quiero que tenga que hacerse en ofApp esta verificacion! en ofApp solo quiero definir el comportamiento de mi aplicacion cuando van terminando diferentes tweens, para gestionar mi states machine.

## HOWTO: RULES:

- preguntame tus dudas antes de empezar o implementar
- hazme propuestas antes de implementar
- no tocar ofxTweenLite, ya que la classe main no es hecha por mi y quiero mantener la dependencia intacta
- no toques mis lineas conectadas
- no cambies cosas sin pedirme autorizacion, por favor

## ----------

## IGNORE: Future Ideas

- Add animation sequences/timelines

## ----------

# DONE: CHANGELOG:

## October 30, 2025

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