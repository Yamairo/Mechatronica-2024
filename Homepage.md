---
created: 2024-09-19T08:59
updated: 2025-06-03T16:16
---

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

# Boeken
```dataview
LIST
FROM "Boeken"
SORT file.name ASC
```

# Vakken

```toc
```

## Bassiswiskunde
```dataview
LIST
FROM "Bassiswiskunde"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Communicatieve Vaardigheden
```dataview
LIST
FROM "Communicatieve Vaardigheden"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Elektrische Netwerken
```dataview
LIST
FROM "Elektrische Netwerken"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Excalidraw

## Industriële Besturing Programmeren
```dataview
LIST
FROM "Industriële Besturing Programmeren"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```
## Microcontroller programmeren
```dataview
LIST
FROM "Excalidraw"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Industriële Besturing Programmeren
```dataview
LIST
FROM "Mechanice"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Mechanica 2
```dataview
LIST
FROM "Mechanica 2"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```


## Microcontroller Programmeren
```dataview
LIST
FROM "Microcontroller Programmeren"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Ontwerpen in Groepen 
```dataview
LIST
FROM "Ontwerpen in groepen"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Project
```dataview
LIST
FROM "Project"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Project Agrobot
```dataview
LIST
FROM "Project Agrobot"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Project AGV
```dataview
LIST
FROM "Project AGV"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Project AGV 2
```dataview
LIST
FROM "Project AGV Deel 2"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```
## Sensoren en Actuatoren
```dataview
LIST
FROM "Sensoren en Actuatoren"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Solidworks
```dataview
LIST
FROM "Solidworks"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Statica
```dataview
LIST
FROM "Statica"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Wiskunde
```dataview
LIST
FROM "Wiskunde"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

## Wiskunde 2
```dataview
LIST
FROM "Wiskunde 2"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

# Extra Informatie

# Bijlages
```dataview
LIST
FROM "Bijlages"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

# Boeken
```dataview
LIST
FROM "Boeken"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

# Subonderwerpen
```dataview
LIST
FROM "Subonderwerpen"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```

# Templates
```dataview
LIST
FROM "Templates"
FLATTEN "## " + file.link AS heading
SORT file.name ASC
```