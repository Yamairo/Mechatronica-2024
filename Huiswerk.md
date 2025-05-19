---
created: 2024-09-10T12:03
updated: 2025-05-19T11:48
---



```dataview
TABLE WITHOUT ID 
  regexreplace(Tasks.text, "\[.*$", "") AS Huiswerk, 
  choice(Tasks.completed, "✅", "❌") AS Status, 
  Tasks.Startdatum AS "Startdatum", 
  Tasks.Einddatum AS "Einddatum",  
  Tasks.Prioriteit AS "Prioriteit", 
  regexreplace(Tasks.subtasks.text, "\[.*$", "") AS Subtasks, 
  join(choice(Tasks.subtasks.completed, "✅", "❌"), " ") AS "Subtaken"
FROM "Huiswerk"
FLATTEN file.tasks AS Tasks
WHERE !Tasks.completed
```


- [x] Planning maken [Startdatum :: 10-09-2024 ] [Einddatum :: 10-09-2024 ] [Prioriteit :: Hoog] 
- [x] Programmeren week 2 [Startdatum :: 15-09-2024 ] [Einddatum :: 20-09-2024 ] [Prioriteit :: Midden] 
- [x] Möbius Simulatie Week 2 [Startdatum :: 15-09-2024 ] [Einddatum :: 16-09-2024 ] [Prioriteit :: Hoog] 
- [x] Möbius Mechanica [Startdatum :: 11-09-2024 ] [Einddatum :: 17-09-2024 ] [Prioriteit :: Hoog] 
- [x] Wiskunde 
	- [x] 4.3: Grafieken van lineaire functies – blz: 84 [Startdatum :: 15-09-2024 ] [Einddatum :: 18-09-2024 ] [Prioriteit :: ]
	- [x] 4.3: Grafieken van lineaire functies–1, 2, 3, 4, 5 [Startdatum :: 18-09-2024 ] [Einddatum :: 24-09-2024 ] [Prioriteit :: Laag] 	

## Week 3
- [x] Lees 'Eisen van eisen. Pdf' [Startdatum :: 17-09-2024 ] [Einddatum :: 24-09-2024 ] [Prioriteit  :: Midden]
- [x] Inleveren van Lijst van eisen [Startdatum :: 17-09-2024 ] [Einddatum :: 23-09-2024 ] [Prioriteit  ::  ]

## Week 4
- [x] Solderen H-Brug [Startdatum :: 02-10-2024 ] [Einddatum :: 02-10-2024 ] [Prioriteit  ::  Hoog]
	- [x] Inleveren opdracht [Startdatum :: 02-10-2024 ] [Einddatum :: 02-10-2024 ] [Prioriteit  :: Hoog ]
- [x] Methodisch ontwerpen inleveren [Startdatum :: 02-10-2024 ] [Einddatum :: 09-10-2024 ] [Prioriteit  ::  Hoog]

## Week 5