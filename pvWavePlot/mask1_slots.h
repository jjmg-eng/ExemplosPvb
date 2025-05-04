//###############################################################
//# mask1_slots.h for ProcessViewServer created: dom. mai. 4 10:30:03 2025
//# please fill out these slots
//# here you find all possible events
//# Yours: Lehrig Software Engineering
//###############################################################

// todo: uncomment me if you want to use this data aquisiton
// also uncomment this classes in main.cpp and pvapp.h
// also remember to uncomment rllib in the project file
//extern rlModbusClient     modbus;  //Change if applicable
//extern rlSiemensTCPClient siemensTCP;
//extern rlPPIClient        ppi;

typedef struct // (todo: define your data structure here)
{
  rlSvgAnimator s;
  char svgFile[80];
  float a,f,p;
  int w;
  int c;
}
DATA;

static int slotInit(PARAM *p, DATA *d)
{
  if(p == NULL || d == NULL) return -1;
  //memset(d,0,sizeof(DATA));
  d->a = 1; d->f = 5; d->p = 30; d->w = 0;
  d->c = 2;
  int value = 100 * (d->a - 1) / 9.0;
  pvSetValue(p,AMP,value);
  pvPrintf(p,AMP_lable,"Amplitude: %g",value*9.0/100.0+1.0);

  value = 100 * (d->f - 1) / 9.0;
  pvSetValue(p,FREQ,value);
  pvPrintf(p,FREQ_lable,"Frequency: %g",value*9.0/100.0+1.0);

  value = 100 * (d->p) / 360.0;
  pvSetValue(p,PHASE,value);
  pvPrintf(p,PHASE_lable,"Phase: %g",value*360.0/100.0);

  sprintf(d->svgFile,"%splot.svg",p->file_prefix);
  wavePlot(d->svgFile, d->a, d->f, d->p, d->w);

  for(int i = 0; waveform[i][0]; i++)   pvInsertItem(p, WAVE, -1, NULL, waveform[i]);
  pvSetCurrentItem(p,WAVE,0);

  initSVG(p, mySVG, &d->s, d->svgFile, 21,21,720,288,1.0);

  return 0;
}

static int slotNullEvent(PARAM *p, DATA *d)
{
  if(p == NULL || d == NULL) return -1;

  if(d->c == 2) wavePlot(d->svgFile, d->a, d->f, d->p, d->w);
  if(d->c == 0) {
      d->s.read(d->svgFile);
      d->c = -1;
  }
  if(d->c > 0) d->c--;

  drawSVG(p,mySVG,&d->s);

  return 0;
}

static int slotButtonEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotButtonPressedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotButtonReleasedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotTextEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  int j = -1;
  switch(id) {
  case WAVE: for(int i = 0; waveform[i][0]; i++)   if(!strcmp(waveform[i],text)) j = i;
             if(j >= 0)  d->w = j;
             d->c = 2;
             break;
  }
  return 0;
}

static int slotSliderEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  switch(id){
  case AMP:d->a = val*9.0/100.0+1.0;
           pvPrintf(p,AMP_lable,"Amplitude: %g",d->a);
           break;
  case FREQ:d->f = val*9.0/100.0+1.0;
           pvPrintf(p,FREQ_lable,"Frequency: %g",d->f);
           break;
  case PHASE:d->p = val*360.0/100.0;
           pvPrintf(p,PHASE_lable,"Phase: %g",d->p);
           break;
  }
  d->c = 3;
  return 0;
}

static int slotCheckboxEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotRadioButtonEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotGlInitializeEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotGlPaintEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotGlResizeEvent(PARAM *p, int id, DATA *d, int width, int height)
{
  if(p == NULL || id == 0 || d == NULL || width < 0 || height < 0) return -1;
  return 0;
}

static int slotGlIdleEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotTabEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotTableTextEvent(PARAM *p, int id, DATA *d, int x, int y, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || text == NULL) return -1;
  return 0;
}

static int slotTableClickedEvent(PARAM *p, int id, DATA *d, int x, int y, int button)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || button < 0) return -1;
  return 0;
}

static int slotSelectionEvent(PARAM *p, int id, DATA *d, int val, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000 || text == NULL) return -1;
  return 0;
}

static int slotClipboardEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == -1 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotRightMouseEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  //pvPopupMenu(p,-1,"Menu1,Menu2,,Menu3");
  return 0;
}

static int slotKeyboardEvent(PARAM *p, int id, DATA *d, int val, int modifier)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000 || modifier < -1000) return -1;
  return 0;
}

static int slotMouseMovedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMousePressedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMouseReleasedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMouseOverEvent(PARAM *p, int id, DATA *d, int enter)
{
  if(p == NULL || id == 0 || d == NULL || enter < -1000) return -1;
  return 0;
}

static int slotUserEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}
