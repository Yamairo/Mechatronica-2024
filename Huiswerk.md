---
created: 2024-09-10T12:03
updated: 2024-09-17T11:55
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
- [ ] Programmeren week 2 [Startdatum :: 15-09-2024 ] [Einddatum :: 20-09-2024 ] [Prioriteit :: Midden] 
- [x] Möbius Simulatie Week 2 [Startdatum :: 15-09-2024 ] [Einddatum :: 16-09-2024 ] [Prioriteit :: Hoog] 
- [ ] Möbius Mechanica [Startdatum :: 11-09-2024 ] [Einddatum :: 17-09-2024 ] [Prioriteit :: Hoog] 
- [ ] Wiskunde 
	- [x] 4.3: Grafieken van lineaire functies – blz: 84 [Startdatum :: 15-09-2024 ] [Einddatum :: 18-09-2024 ] [Prioriteit :: ]
	- [ ] 4.3: Grafieken van lineaire functies–1, 2, 3, 4, 5 [Startdatum :: 18-09-2024 ] [Einddatum :: 24-09-2024 ] [Prioriteit :: Laag] 	

## Week 3
- [ ] Lees 'Eisen van eisen. Pdf' [Startdatum :: 17-09-2024 ] [Einddatum :: 24-09-2024 ] [Prioriteit  :: Midden]
- [ ] Inleveren van Lijst van eisen [Startdatum :: 17-09-2024 ] [Einddatum :: 23-09-2024 ] [Prioriteit  ::  ]
