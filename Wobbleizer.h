#ifndef __WOBBLEIZER__
#define __WOBBLEIZER__

#include <sstream>
#include "IPlug_include_in_plug_hdr.h"
#include "FilterControler.h"
#include "Oscillator.h"
#include "RearmClock.h"
#include "Enum.h"
#include "EffectRack.h"
#include"ParameterPrinterControl.h"
#include "DebugPanelControl.h"

class Wobbleizer : public IPlug
{
public:
  Wobbleizer(IPlugInstanceInfo instanceInfo);
  ~Wobbleizer();

  void Reset();
  void OnParamChange(int paramIdx);
  void ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames);
  void ApplyFilter(double** inputs, double** outputs, int nFrames);

private:
	FilterControler mFilter;
	Oscillator mLFO;
	RearmClock mRearmClock;
	EffectRack mEffectRack;
	double mLFOFilterModAmount;
	bool mRearmOnFrequencyUpdate;

	ParameterPrinterControl * parameterPrinter;
	DebugPanelControl * debugPanel;

};

#endif