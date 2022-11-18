# Bib.i

*4th project of our 2nd year in GTECH 2.*
Made in collaboration with [Guilian PIPART](https://github.com/Lum0o) and [Noah WIART](https://github.com/nwiart)
[DIAPO](https://docs.google.com/presentation/d/1nqnWrATYoPwu3ZxxI8SHNYyPmS74f1MHcB90rjBoOjs/edit?usp=sharing)

## PROBLEM :  
> After a little analysis, we realized that there was no application for parents to record their babies' bottle feeds.

## SOFTWARE FEATURES: 
	- Possibility to add the hours of taking the baby's bottle
	- Ability to add the amount of milk ingested by the baby 
	- Create a variable interval reminder to give the baby a bottle
	- Take into account the possibility that the baby regurgitates his bottle
	- Create a shopping list for the baby

## SUMMARY
1. ** Bottle feeding **
    - Same quantity taken each time for the baby.
    - Check if the quantity_min is sufficient for the next feeding:
        -> if yes: recall for the next feeding
        -> if not: refill
2. ** Regurgitation **
    - Note the quantity regurgitated and the date
3. ** Reminder **
    - Next intake = time of intake + reminder
    - Notification
4. ** Add milk quantity **
    - If actual_quantity < quantity_min && If we are not after 20H
        -> refill
5. ** Shopping List **
    - Keep tracks of the remaining & necessary products
    - Indicates when to buy the products
