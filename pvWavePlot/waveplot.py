import sys
import numpy as np
import matplotlib.pyplot as plt

def generate_waveform(amplitude, frequency, phase, wave_type, duration=1.0, sample_rate=1000):
    t = np.linspace(0, duration, int(sample_rate * duration), endpoint=False)
    phase_rad = np.deg2rad(phase)

    if wave_type == 'sine':
        y = amplitude * np.sin(2 * np.pi * frequency * t + phase_rad)
    elif wave_type == 'square':
        y = amplitude * np.sign(np.sin(2 * np.pi * frequency * t + phase_rad))
    elif wave_type == 'triangle':
        y = amplitude * (2 * np.arcsin(np.sin(2 * np.pi * frequency * t + phase_rad)) / np.pi)
    else:
        raise ValueError("Unsupported wave type: choose 'sine', 'square', or 'triangle'")
    
    return t, y

def main():
    if len(sys.argv) < 5:
        print("Usage: python waveplot.py <amplitude> <frequency> <phase_deg> <wave_type> [--export-svg <filename>]")
        sys.exit(1)
    
    amplitude = float(sys.argv[1])
    frequency = float(sys.argv[2])
    phase = float(sys.argv[3])
    wave_type = sys.argv[4].lower()

    export_svg = False
    svg_filename = "waveform.svg"

    if "--export-svg" in sys.argv:
        idx = sys.argv.index("--export-svg")
        if idx + 1 < len(sys.argv):
            svg_filename = sys.argv[idx + 1]
            export_svg = True
        else:
            print("Missing filename after --export-svg")
            sys.exit(1)

    t, y = generate_waveform(amplitude, frequency, phase, wave_type)

    plt.figure(figsize=(10, 4))
    plt.plot(t, y, label=f'{wave_type.capitalize()} Wave')
    plt.title(f'{wave_type.capitalize()} Waveform')
    plt.xlabel('Time [s]')
    plt.ylabel('Amplitude')
    plt.grid(True)
    plt.legend()
    
    if export_svg:
        plt.savefig(svg_filename, format='svg')
        print(f"SVG exported to {svg_filename}")
    else:
        plt.show()

if __name__ == "__main__":
    main()
