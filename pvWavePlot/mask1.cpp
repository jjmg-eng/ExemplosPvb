////////////////////////////////////////////////////////////////////////////
//
// show_mask1 for ProcessViewServer created: dom. mai. 4 10:30:03 2025
//
////////////////////////////////////////////////////////////////////////////
#include "pvapp.h"

////////////////////////////////////////////////////////////////////////////
// Código adicionado
static const char *waveform[] ={
" Sine",
" Square",
" Triangle",
"" };

int wavePlot(char* fileName, float amp, float freq, float phase, int wave)
{
  char buf[128];
  sprintf(buf, "python waveplot.py %g %g %g %s --export-svg %s > /dev/null", amp, freq, phase, wave == 0 ? "sine" :
          wave == 1 ? "square" : "triangle", fileName);
  return system(buf);
}

int drawSVG(PARAM *p, int id,rlSvgAnimator *s)
{
	if(s->isModified == 0) return 0;
	gBeginDraw(p,id);
	s->writeSocket();
	gEndDraw(p);
	return 0;
}

int initSVG(PARAM *p, int id, rlSvgAnimator *s, const char *filename, int x, int y, int w, int h, float SCALE)
{
	pvSetGeometry(p,id,x,y,w*SCALE,h*SCALE);
	s->setSocket(&p->s);
	s->setId(id);
	s->read(filename);
	s->setScale(SCALE);
	s->setWindowSize(w,h);
	s->setMainObject("main");
	s->setMatrix ("main", SCALE, 0, 0, 0, 0, 0);
        pvSetPaletteBackgroundColor(p, id, BG_COLOR);
	return 0;	
}

// fim do código adicionado
////////////////////////////////////////////////////////////////////////////


// _begin_of_generated_area_ (do not edit -> use ui2pvc) -------------------

// our mask contains the following objects
enum {
  ID_MAIN_WIDGET = 0,
  mySVG,
  AMP,
  AMP_lable,
  FREQ,
  FREQ_lable,
  PHASE,
  PHASE_lable,
  WAVE,
  ID_END_OF_WIDGETS
};

// our mask contains the following widget names
  static const char *widgetName[] = {
  "ID_MAIN_WIDGET",
  "mySVG",
  "AMP",
  "AMP_lable",
  "FREQ",
  "FREQ_lable",
  "PHASE",
  "PHASE_lable",
  "WAVE",
  "ID_END_OF_WIDGETS",
  ""};

  static const char *toolTip[] = {
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  ""};

  static const char *whatsThis[] = {
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  ""};

  static const int widgetType[ID_END_OF_WIDGETS+1] = {
  0,
  TQDraw,
  TQSlider,
  TQLabel,
  TQSlider,
  TQLabel,
  TQSlider,
  TQLabel,
  TQComboBox,
  -1 };

static int generated_defineMask(PARAM *p)
{
  int w,h,depth;

  if(p == NULL) return 1;
  if(widgetName[0] == NULL) return 1; // suppress unused warning
  w = h = depth = strcmp(toolTip[0],whatsThis[0]);
  if(widgetType[0] == -1) return 1;
  if(w==h) depth=0; // fool the compiler
  pvStartDefinition(p,ID_END_OF_WIDGETS);

  pvQDraw(p,mySVG,0);
  pvSetGeometry(p,mySVG,21,21,99,30);
  pvSetFont(p,mySVG,"Ubuntu",11,0,0,0,0);

  pvQSlider(p,AMP,0,0,100,1,8,Horizontal);
  pvSetGeometry(p,AMP,21,350,300,30);
  pvSetFont(p,AMP,"Ubuntu",11,0,0,0,0);

  pvQLabel(p,AMP_lable,0);
  pvSetGeometry(p,AMP_lable,339,348,300,30);
  pvSetText(p,AMP_lable,pvtr("Label"));
  pvSetFont(p,AMP_lable,"Ubuntu",11,0,0,0,0);

  pvQSlider(p,FREQ,0,0,100,1,0,Horizontal);
  pvSetGeometry(p,FREQ,21,390,300,30);
  pvSetFont(p,FREQ,"Ubuntu",11,0,0,0,0);

  pvQLabel(p,FREQ_lable,0);
  pvSetGeometry(p,FREQ_lable,340,390,300,30);
  pvSetText(p,FREQ_lable,pvtr("Label"));
  pvSetFont(p,FREQ_lable,"Ubuntu",11,0,0,0,0);

  pvQSlider(p,PHASE,0,0,100,1,0,Horizontal);
  pvSetGeometry(p,PHASE,21,430,300,30);
  pvSetFont(p,PHASE,"Ubuntu",11,0,0,0,0);

  pvQLabel(p,PHASE_lable,0);
  pvSetGeometry(p,PHASE_lable,339,429,300,30);
  pvSetText(p,PHASE_lable,pvtr("Label"));
  pvSetFont(p,PHASE_lable,"Ubuntu",11,0,0,0,0);

  pvQComboBox(p,WAVE,0,0,AtBottom);
  pvSetGeometry(p,WAVE,21,470,300,30);
  pvSetFont(p,WAVE,"Ubuntu",11,0,0,0,0);


  pvEndDefinition(p);
  return 0;
}

// _end_of_generated_area_ (do not edit -> use ui2pvc) ---------------------

#include "mask1_slots.h"

static int defineMask(PARAM *p)
{
  if(p == NULL) return 1;
  generated_defineMask(p);
  // (todo: add your code here)
  return 0;
}


static int showData(PARAM *p, DATA *d)
{
  if(p == NULL) return 1;
  if(d == NULL) return 1;
  return 0;
}

static int readData(DATA *d) // from shared memory, database or something else
{
  if(d == NULL) return 1;
  // (todo: add your code here)
  return 0;
}


int show_mask1(PARAM *p)
{
  DATA d;
  char event[MAX_EVENT_LENGTH];
  char text[MAX_EVENT_LENGTH];
  char str1[MAX_EVENT_LENGTH];
  int  i,w,h,val,x,y,button,ret;
  float xval, yval;

  defineMask(p);
  //rlSetDebugPrintf(1);
  if((ret=slotInit(p,&d)) != 0) return ret;
  readData(&d); // from shared memory, database or something else
  showData(p,&d);
  pvClearMessageQueue(p);
  while(1)
  {
    pvPollEvent(p,event);
    switch(pvParseEvent(event, &i, text))
    {
      case NULL_EVENT:
        readData(&d); // from shared memory, database or something else
        showData(p,&d);
        if((ret=slotNullEvent(p,&d)) != 0) return ret;
        break;
      case BUTTON_EVENT:
        if(trace) printf("BUTTON_EVENT id=%d\n",i);
        if((ret=slotButtonEvent(p,i,&d)) != 0) return ret;
        break;
      case BUTTON_PRESSED_EVENT:
        if(trace) printf("BUTTON_PRESSED_EVENT id=%d\n",i);
        if((ret=slotButtonPressedEvent(p,i,&d)) != 0) return ret;
        break;
      case BUTTON_RELEASED_EVENT:
        if(trace) printf("BUTTON_RELEASED_EVENT id=%d\n",i);
        if((ret=slotButtonReleasedEvent(p,i,&d)) != 0) return ret;
        break;
      case TEXT_EVENT:
        if(trace) printf("TEXT_EVENT id=%d %s\n",i,text);
        if((ret=slotTextEvent(p,i,&d,text)) != 0) return ret;
        break;
      case SLIDER_EVENT:
        sscanf(text,"(%d)",&val);
        if(trace) printf("SLIDER_EVENT val=%d\n",val);
        if((ret=slotSliderEvent(p,i,&d,val)) != 0) return ret;
        break;
      case CHECKBOX_EVENT:
        if(trace) printf("CHECKBOX_EVENT id=%d %s\n",i,text);
        if((ret=slotCheckboxEvent(p,i,&d,text)) != 0) return ret;
        break;
      case RADIOBUTTON_EVENT:
        if(trace) printf("RADIOBUTTON_EVENT id=%d %s\n",i,text);
        if((ret=slotRadioButtonEvent(p,i,&d,text)) != 0) return ret;
        break;
      case GL_INITIALIZE_EVENT:
        if(trace) printf("you have to call initializeGL()\n");
        if((ret=slotGlInitializeEvent(p,i,&d)) != 0) return ret;
        break;
      case GL_PAINT_EVENT:
        if(trace) printf("you have to call paintGL()\n");
        if((ret=slotGlPaintEvent(p,i,&d)) != 0) return ret;
        break;
      case GL_RESIZE_EVENT:
        sscanf(text,"(%d,%d)",&w,&h);
        if(trace) printf("you have to call resizeGL(w,h)\n");
        if((ret=slotGlResizeEvent(p,i,&d,w,h)) != 0) return ret;
        break;
      case GL_IDLE_EVENT:
        if((ret=slotGlIdleEvent(p,i,&d)) != 0) return ret;
        break;
      case TAB_EVENT:
        sscanf(text,"(%d)",&val);
        if(trace) printf("TAB_EVENT(%d,page=%d)\n",i,val);
        if((ret=slotTabEvent(p,i,&d,val)) != 0) return ret;
        break;
      case TABLE_TEXT_EVENT:
        sscanf(text,"(%d,%d,",&x,&y);
        pvGetText(text,str1);
        if(trace) printf("TABLE_TEXT_EVENT(%d,%d,\"%s\")\n",x,y,str1);
        if((ret=slotTableTextEvent(p,i,&d,x,y,str1)) != 0) return ret;
        break;
      case TABLE_CLICKED_EVENT:
        sscanf(text,"(%d,%d,%d)",&x,&y,&button);
        if(trace) printf("TABLE_CLICKED_EVENT(%d,%d,button=%d)\n",x,y,button);
        if((ret=slotTableClickedEvent(p,i,&d,x,y,button)) != 0) return ret;
        break;
      case SELECTION_EVENT:
        sscanf(text,"(%d,",&val);
        pvGetText(text,str1);
        if(trace) printf("SELECTION_EVENT(column=%d,\"%s\")\n",val,str1);
        if((ret=slotSelectionEvent(p,i,&d,val,str1)) != 0) return ret;
        break;
      case CLIPBOARD_EVENT:
        sscanf(text,"(%d",&val);
        if(trace) printf("CLIPBOARD_EVENT(id=%d)\n",val);
        if((ret=slotClipboardEvent(p,i,&d,val)) != 0) return ret;
        break;
      case RIGHT_MOUSE_EVENT:
        if(trace) printf("RIGHT_MOUSE_EVENT id=%d text=%s\n",i,text);
        if((ret=slotRightMouseEvent(p,i,&d,text)) != 0) return ret;
        break;
      case KEYBOARD_EVENT:
        sscanf(text,"(%d",&val);
        if(trace) printf("KEYBOARD_EVENT modifier=%d key=%d\n",i,val);
        if((ret=slotKeyboardEvent(p,i,&d,val,i)) != 0) return ret;
        break;
      case PLOT_MOUSE_MOVED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        if(trace) printf("PLOT_MOUSE_MOVE %f %f\n",xval,yval);
        if((ret=slotMouseMovedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case PLOT_MOUSE_PRESSED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        if(trace) printf("PLOT_MOUSE_PRESSED %f %f\n",xval,yval);
        if((ret=slotMousePressedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case PLOT_MOUSE_RELEASED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        if(trace) printf("PLOT_MOUSE_RELEASED %f %f\n",xval,yval);
        if((ret=slotMouseReleasedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case MOUSE_OVER_EVENT:
        sscanf(text,"%d",&val);
        if(trace) printf("MOUSE_OVER_EVENT %d\n",val);
        if((ret=slotMouseOverEvent(p,i,&d,val)) != 0) return ret;
        break;
      case USER_EVENT:
        if(trace) printf("USER_EVENT id=%d %s\n",i,text);
        if((ret=slotUserEvent(p,i,&d,text)) != 0) return ret;
        break;
      default:
        if(trace) printf("UNKNOWN_EVENT id=%d %s\n",i,text);
        break;
    }
  }
}
