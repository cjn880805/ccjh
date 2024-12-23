// ����
// greenxiao.h 2001-04-04

EQUIP_BEGIN(CIgreenxiao);

virtual void create(int nFlag = 0)
{
	set_name("�����᡹", "green xiao");
	set_weight(1000);
    
	set("wield_position", WIELD_RIGHT_HAND);
	
	set("unit", "��");
	set("long", "һ֧���µ����");
	set("value", 10000);
				
	set("apply/damage", 200);
	set("apply/per", 10);
	
	set("no_sell", 1);
	set("skill_type", "music");
	set("music_type", "xiao");
	
	set("wield_msg", "$HIG$N����̾�������䴦�����һ֧$n$HIG����̧�ۣ����ֵ����⡣");
	set("unwield_msg", "$HIG$N��̾�������ջ�$n$HIG��");

//	call_out(do_die, 3600);	
}

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
		destruct(ob);
	else
		ob->call_out(do_die, 3600);
}
EQUIP_END;