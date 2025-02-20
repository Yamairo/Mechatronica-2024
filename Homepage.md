---
created: 2024-09-19T08:59
updated: 2025-02-20T11:12
---
```toc
```

# Te doen
Voor meer zie [[Huiswerk]]
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

# Elektrische Netwerken
```dataview
LIST
FROM "Elektrische Netwerken"
FLATTEN "## " + file.link AS heading
```

# Microcontroller programmeren
```dataview
LIST
FROM "Microcontroller Programmeren"
FLATTEN "## " + file.link AS heading
```

# Mechanica 2
```dataview
LIST
FROM "Mechanica 2"
FLATTEN "## " + file.link AS heading
```

# Ontwerpen in Groepen 
```dataview
LIST
FROM "Ontwerpen in groepen"
FLATTEN "## " + file.link AS heading
```

# Sensoren en Actuatoren
```dataview
LIST
FROM "Sensoren en Actuatoren"
FLATTEN "## " + file.link AS heading
```

# Wiskunde
```dataview
LIST
FROM "Wiskunde"
FLATTEN "## " + file.link AS heading
```



