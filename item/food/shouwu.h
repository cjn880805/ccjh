//shouwu.h

//Sample for ITEM 何首乌
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIshouwu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "何首乌");	//set item name

	set_weight(100);

	set("unit", "支");
	set("long", "这是一支已成人形的何首乌，看来可以入药。");
	set("value", 10000);
 
};
virtual int do_use(CChar * me, CContainer * target)
{
	if (me->query("max_hp")<=200) 
	{
		tell_object(me,"你吃下了一支何首乌，只觉得精神健旺之极。");
		me->add("max_hp",2);
		me->add("hp",100);
	}
	else
	{
		tell_object(me,"你吃下了一支何首乌，但是好象没什么用。");
	}
	destruct(this);
	me->unconcious();
	return 1;

}
/****************
int do_eat(string arg)
{
      if(arg=="shouwu")
        {
                if (me->query("max_jingli")<=200) {
                        write("你吃下了一支何首乌，只觉得精神健旺之极。\n");
                        me->add("max_jingli",2);
                        me->add("jingli",2);
                }
                else {
                        write("你吃下了一支何首乌，但是好象没什么用。\n");
                }
                destruct(this_object());
                me->unconcious();
        }
        return 1;
}
********************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp