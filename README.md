# Flying_Schlumpf# Motorisierter Looping-Loui Nachbau

Willkommen beim Projekt zum elektrischen Nachbau von **Looping-Loui**!  
Dieses Repository enthält sämtliche Hardware- und Software-Ressourcen sowie ausführliche Dokumentation, um das beliebte Geschicklichkeitsspiel elektrisch zu betreiben und individuell nachzubauen.

## Inhaltsverzeichnis

- [Projektüberblick](#projektüberblick)
- [Vorprojekte](#vorprojekte)
- [Repository-Struktur](#repository-struktur)
- [Verwendete Tools](#verwendete-tools)
- [Mitmachen](#mitmachen)
- [Lizenz](#lizenz)

## Projektüberblick

Ziel dieses Projekts ist es, eine motorbetriebene Version des Spiels „Looping-Loui“ zu bauen. Das Originalspiel wird elektrisch angesteuert, sodass Geschwindigkeit, Bewegungsrichtung und Logik flexibel per Software gesteuert werden können. Die Hardware basiert auf den Open-Source-Werkzeugen **KiCad** (für Elektronik) und **FreeCAD** (für mechanische Komponenten).  
Das Projekt ist komplett in Deutsch dokumentiert.

## Vorprojekte

Die Entwicklung basiert auf Erkenntnissen und Lösungen aus früheren Projekten:

- [hardware design for trigger of flying schlumpf](https://github.com/RT-CUSTOMZ/Flying_Schlumpf_Trigger_HW)
- [Steuerung des Arms (SW)](https://github.com/RT-CUSTOMZ/FlyingSchlumpfController)
- [Steuerung des Arms (HW)](https://github.com/RT-CUSTOMZ/FlyingSchlumpfControllerHardware)
- [Handsteuerung für die Spielenden](https://github.com/RT-CUSTOMZ/FlyingSchlumpfRemote)

Bitte die Links zu den tatsächlichen Vorprojekten im finalen README ersetzen!

## Repository-Struktur

```text
/
├── SW/             ← Quellcode & Software, z.B. C, C++, Arduino Sketches, Python
├──────FS_Base      ← Ansteuerung der Basis mit dem Drehteller
├── HW/             ← Hardwaredateien (Schaltpläne, Layouts, 3D-Modelle)
├── Dok/            ← Dokumentation (Anleitungen, Bilder, Stücklisten)
└── README.md       ← Projektdokumentation und Einstiegspunkt
```

### Details zu den Verzeichnissen

- **SW/**: Enthält den vollständigen Quellcode für die Motorsteuerung und Schnittstellen zu Mikrocontrollern.
- **HW/**: Alle relevanten Dateien aus KiCad (Schaltplan/Layout) und FreeCAD (3D-Modelle für Druckteile, Gehäuse etc.).
- **Dok/**: Aufbauanleitungen, Stücklisten, Fotos und weiterführende Dokumente zur Inbetriebnahme.

## Verwendete Tools

- **KiCad:** Elektronikentwicklung (Schaltplan & PCB)
- **FreeCAD:** Entwicklung und Modifikation der mechanischen Teile
- **VSCode:** IDE des Projektes

## Mitmachen

- Pull-Requests sind ausdrücklich willkommen!
- Bitte beachte die Struktur und die Dokumentationsstandards des Projekts.
- Bei Fragen oder Interesse an einer Mitarbeit: Issue eröffnen oder direkt Kontakt aufnehmen.

## Lizenz

Dieses Projekt steht unter einer Open-Source-Lizenz (bitte konkrete Lizenz eintragen, z.B. **MIT** oder **CERN OHL**).

### Viel Spaß beim Nachbauen und Tüfteln!