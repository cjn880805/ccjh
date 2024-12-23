//sanxiaosan.h

//Sample for ITEM ��Ц��ңɢ
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIsanxiaosan);

//under, we will custom our item

void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��Ц��ңɢ");	//set item name

	set("long", "һ����ɫ�ķ�ĩ, �����Ӳ���Ѱ����Ʒ. ");
	set("unit", "��");
	set("pour_type", "sanxiao_poison");
	set("value", 20000);
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set("unit", "Щ");

	set("material", "iron");
	set("wield_msg", "$N��Ϣ�������г�һ����Ц��ңɢ����");
	set("unwield_msg","$NС������ؽ��������Ц��ңɢ�Ž����");
	set_amount(1);
	
	set("apply/damage", 1);					//set the modifiers of attribute

};

const char * hit_ob(CChar *me, CChar *target, LONG damage)
{
	if(me->query_skill("poison",1) < 250 &&
		 ( me->query_skill("force", 1) > target->query_skill("force")) ) 
	{
			target->apply_condition("sanxiao_poison", target->query_condition("sanxiao_poison") + 3);
			return 0;
	}
	
	me->apply_condition("sanxiao_poison", me->query_condition("sanxiao_poison") + 3);
	
	return 0;
}	

int do_use(CChar * me, CContainer * target)
{
	message_vision("$N��ͷ����һ��$n", me, this);
	me->die();
	destruct(this);
	return 1;

}
/****************
int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="san" || arg=="xiaoyao san")
	{
		message_vision("$N��ͷ����һ��" + name() + "��\n", me);
		this_player()->die();
		destruct(this_object());
	}
	return 1;
}
***************/
EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp