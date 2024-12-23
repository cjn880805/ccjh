//xuedao.h

//Sample for ITEM: Ѫ��
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIxuedao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Ѫ��");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(1000);		//set item weight

	set("unit", "��");
	set("long",  "����һ�Ѳ�������ı�����������ŵ�����ѪӰ��"  );
	set("value", 1000);
	set("material", "steel");
	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n��ص��ʡ�");
// 	init_blade(20);
	set("apply/damage", 60);					//set the modifiers of attribute

};
/************************
int do_wield(string arg)
{
        object me=this_player();

        object ob;
        string str;
	int i, count;

        if (!id(arg))   return notify_fail("��Ҫװ��ʲô��\n");


	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");


	if( ob->wield() ) {
              if( !stringp(str = ob->query("wield_msg")) )
			str = "$Nװ��$n��������\n";
              message_vision(str, me, ob);
              if ( me->query_skill("xue-dao")
              && me->query_skill_mapped("blade") == "xue-dao" )
			me->add_temp("apply/damage",200);

              return 1;
	}

        else
                return 0;
}
int do_unwield(string arg)
{
        object me=this_player();
	object ob, *inv;
	string str;
	int i;

	if( !arg ) return notify_fail("��Ҫ�ѵ�ʲô��\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if(  ob->query("equipped")!="wielded" )
		return notify_fail("�㲢û��װ������������Ϊ������\n");

	if( ob->unequip() ) {
		if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N�������е�$n��\n";
		message_vision(str, me, ob);
		if ( me->query_skill("xue-dao")
			&& me->query_skill_mapped("blade") == "xue-dao" )
			me->add_temp("apply/damage", -380);

		return 1;
	} else
		return 0;
}


********************/
EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp