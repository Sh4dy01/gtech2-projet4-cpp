# gtech2-proj4-cpp
*4th project of my 2nd year GTECH 2.*

## PROBLEM :  
> After a little analysis, we realized that there was no application for parents to record their babies' bottle feeds.

## SOFTWARE FEATURES: 
	- Possibility to add the hours of taking the baby's bottle
	- Ability to add the amount of milk ingested by the baby 
	- Create a variable interval reminder to give the baby a bottle
	- Take into account the possibility that the baby regurgitates his bottle
	- Create a shopping list for the baby

## APP STRUCTURE :
```cpp
class bottle{
    private:
        int max_capacity;
        int actual_quantity;
        int quantity_min;
        int reminder;  
    public:
        void Refill();
        void BottleReduction(int);
};

class feeding{
    private:
        int quantity;
        char take_time;
        bool IsRegurgitated;
};
```

1. Bottle feeding
    - Same quantity taken each time for the baby.
    - Check if the quantity_min is sufficient for the next feeding:
        -> if yes: recall for the next feeding
        -> if not: refill
2. Regurgitation
    - Note the quantity regurgitated and the date
3. Reminder
    - Next intake = time of intake + reminder
    - Notification
4. Add milk quantity
    - If actual_quantity < quantity_min && If we are not after 20H
        -> refill
5. Shopping List