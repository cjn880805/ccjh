//huaban.h
EQUIP_BEGIN(CIhuaban)

virtual void create(int nFlag = 0)		
{
	set_name("����", "hua ban");
	
    set("wield_position", WIELD_HEAD);	
	set_weight(8000);
	
	set("unit", "��");
	set("value", 30000);
	set("material", "plant");

	set("long", "һƬ��֪�Ӻλ������µĻ��꣬����Ũ�����磬����������ˬ��");
	set("wear_msg", "$N����Ц�����������һö$n��");
	set("remove_msg", "$N�����ᣬ����ժ����$n��");

	set("apply/per",15);
	set("apply/armor",15);

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
