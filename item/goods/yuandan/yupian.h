//yupian.h
AUTOCOMBINE_BEGIN(CIyupian)

virtual void create(int nFlag = 0)		
{
	set_name("��Ƭ", "yu pian");
	set("long",	"һ�鲻֪��ʲô�������˱�Ƭ����ɫ��Ө��͸�����������������ɻ�ȡ���");
	set("unit", "Ƭ");
	set_weight(500);

	set_amount(1);
	
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

AUTOCOMBINE_END;




