//cunyang_sword.h
EQUIP_BEGIN(CIcunyang_sword)

virtual void create(int nFlag = 0)		
{
	set_name("������", "cun yang jian");
	
    set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "sword");	
	set_weight(8000);
	
	set("unit", "��");
	set("long", "���������͵�һ��������ͨ��͸�죬������֣�");
	set("value", 1);

	set("apply/damage", random(101)+300);
	set("apply/per", 5);

	set("material", "steel");
	set("wield_msg", "$N����һ��$n����ؼ�Ϊ֮һ����$N�ڽ����ӳ���£��������ݣ����Ʊ��ˡ�");
	set("unwield_msg", "$N��$n������󣬻��������һ�лָ�������");

	call_out(do_die, 3600);	

};

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	//���ϵͳʱ��
	time_t t;	
	struct tm * newtime;

	time(&t);
	newtime = localtime(&t); 

	int month = newtime->tm_mon + 1;
	int day = newtime->tm_mday;

	if(month!=1 ||day>13)
	{
		CContainer * env = load_room("jy");
		if(!env->query("�"))
			destruct(ob);
	}
	else
		ob->call_out(do_die, 3600);
}
EQUIP_END;
