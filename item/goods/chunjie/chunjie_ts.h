//chunjie_ts.h ��ʫ������
//�ز� 2002-03-26

EQUIP_BEGIN(CIchunjie_ts);

virtual void create(int nFlag = 0)	
{
	set_name( "��ʫ������");	

    set("wield_position", WIELD_LEFT_HAND);		//set the position of wield
	set_weight(1000);		//set item weight
	
	set("unit", "��");
	set("long", "һ�������ƴ��ڶ�ʫ��������Ѫ֮����ʫ���������Ķ�����ʹ�����ѧ��Ϊ�õ�������");
	set("value", 1);
	set("apply/int",10);

//	call_out(do_die, 100);	

};

virtual void owner_is_killed(CChar *me)
{
	if(me)
		tell_object(me,"ֻ����ǰ���һ��...������.....");

	destruct(this);
} 

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	//���ϵͳʱ��
	time_t t;	
	struct tm * newtime;

	time(&t);
	newtime = localtime(&t); 

	int month = newtime->tm_mon + 1;

	if(month>=2)
	{
		CContainer * env = load_room("jy");
		if(!env->query("�"))
			destruct(ob);
	}
	else
		ob->call_out(do_die, 3600);

}

EQUIP_END;



