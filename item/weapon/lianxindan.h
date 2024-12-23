//lianxindan.h

//Sample for ITEM: ���ĵ�
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIlianxindan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���ĵ�");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set_weight(1000);		//set item weight
	set("unit", "Щ");
	set("value", 0l);
	set("base_unit", "��");
	set("base_weight", 300);
	set("base_value", 0l);
	set("material", "iron");
	set("long", "���ĵ������������ö���Ũ�����ɵı��������Ｔ������Ѫ����������µ�һ������");
	set("wield_msg", "$N��¶��Ц������һ�����ĵ���˫�ֶ�ʱȼ�������̻�");
	set("unwield_msg","$N������һ������ʣ�µ����ĵ������ջ�¹Ƥ����");
	set_amount(50);
	set("apply/damage", 100);					//set the modifiers of attribute
};

virtual const char * hit_ob(CChar *me, CChar *victim, LONG damage)
{
	if(me->query_skill("huagong_dafa",1) > 30)
		victim->apply_condition("xx_poison", 30);
	return 0;
}	
//����װ������ֵ
int Do_Action(int nAct, CChar * me)
{
	//�ж��з�����
	if(! environment()->is_character()) return 0;
	int ret = 0;

	me = (CChar *)environment();

	if(nAct == DO_WIELD && Query(CAN_EQUIPPED)) 
	{
		//�����Ѫ�����ܣ��˺�������
		if (me->query_skill("poison")
              && ! DIFFERSTR(me->query_skill_mapped("force"), "huagong_dafa" ))
		{
			add("apply/damage",150);
			set("power", 1);
		}

		ret = Do_Wield();
		if(! ret && query("power")) 
		{			
			add("apply/damage", -150);
			del("power");
		}

		return ret;
	}
	
	if(nAct == DO_UNWIELD)
	{
		ret = Do_UnWield();

		if(ret && query("power"))
		{
			add("apply/damage", -150);
			del("power");
		}

		return ret;
	}

	return CItem::Do_Action(nAct, me);
}
EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp