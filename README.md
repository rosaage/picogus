# PiISA / PiGUS

![PiISA Logo](piisa-logo.svg)

ISA card emulation on Raspberry Pi 3, 4, CM4, and Raspberry Pi Pico, initially focusing on Gravis Ultrasound (GUS) sound card emulation.

This is a work in progress in the experimentation phase. It can emulate a GUS and produce sound but things are nowhere near perfect! Please see [the Wiki](https://github.com/polpo/pigus/wiki) for current status.

## For "big" Raspberry Pi:

![pigus-prototype](https://user-images.githubusercontent.com/1544908/182006165-61aa58a7-d336-4c86-becf-883b1548bee1.jpg)

## For Raspberry Pi Pico:

![picogus-prototype](https://user-images.githubusercontent.com/1544908/182006174-71a1792d-ac5b-4c2b-8e61-94a05a0ef55c.jpg)

## Credits

The Raspberry Pi project uses:

* [circle](https://github.com/rsta2/circle) 
* [circle-stdlib](https://github.com/smuehlst/circle-stdlib)
* `gus.cpp` from [DOSBox-staging](https://github.com/dosbox-staging/dosbox-staging)
* Initial PCB design and AdLib emulation based on [RPiISA](https://github.com/eigenco/RPiISA)

The Raspberry Pi Pico project uses:

* [Raspberry Pi Pico C/C++ SDK](https://github.com/raspberrypi/pico-sdk)
* `pico_audio_i2s` from [pico-extras](https://github.com/raspberrypi/pico-extras)
* `stdio_async_uart` from [PicoCart64](https://github.com/kbeckmann/PicoCart64)
* `gus.cpp` from [DOSBox-X](https://github.com/joncampbell123/dosbox-x)
* OPL/AdLib emulation from [rp2040-doom](https://github.com/kilograham/rp2040-doom)

## License

The hardware portions of this repository (hw/, hw-pico/ directories) are licensed under the CERN OHL version 2, permissive.

The software portions of this repository (sw/, sw-pico/, pgusinit/ directories) are licensed under the GNU GPL version 2.