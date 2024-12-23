//xblade.h Ѫ��
//Lanwood 2001-02-07

EQUIP_BEGIN(CIxblade);

//under, we will custom our item

virtual void create(int nFlag = 0)	
{
	set_name("Ѫ��", "blood blade");
	
	set("wield_position", WIELD_RIGHT_HAND);
	set("skill_type", "blade");			//set the skill applied
	set_weight(1000);

	set("unit", "��");
	set("long", "����һ�Ѳ�������ı�����������ŵ�����ѪӰ��");
	set("value", 1000);
	set("material", "steel");
	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n��ص��ʡ�");
	
	set("apply/damage", 20);
};

//����װ������ֵ
int Do_Action(int nAct, CChar * me)
{
	int ret = 0;

	//�ж��з�����
	if(! environment()->is_character()) return 0;
	me = (CChar *)environment();

	if(nAct == DO_WIELD && Query(CAN_EQUIPPED)) 
	{
		//�����Ѫ�����ܣ��˺�������
		if (me->query_skill("xue_dao", 1)
		&& ! DIFFERSTR(me->query_skill_mapped("blade"), "xue_dao" ) && me->query_skill("longxiang", 1)
		&& ! DIFFERSTR(me->query_skill_mapped("force"), "longxiang" ) )
		{
			set("apply/damage",400);
			set("power", 1);
		}

		ret = Do_Wield();
		if(! query("equipped") && query("power")) 
		{			
			set("apply/damage", 20);
			del("power");
		}

		return ret;
	}
	
	if(nAct == DO_UNWIELD)
	{
		ret = Do_UnWield();

		if(! query("equipped") && query("power"))
		{
			set("apply/damage", 20);
			del("power");
		}

		return ret;
	}

	return CItem::Do_Action(nAct, me);
}

EQUIP_END;




