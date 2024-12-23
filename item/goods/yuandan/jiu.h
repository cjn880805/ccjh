//jiu.h ��
//�ز� 2002��12��30

FOOD_BEGIN(CIjiu1);

virtual void create(int nFlag = 0)
{
	static char jiu[10][20]={"Ů����","��Ҷ��","�ſ���","���˼ӷ���","���ҳ��׾�","ę́��","�ھ�","�����Ͻ�","���ϴ�","���"};
	
	int index;
	index=random(10);
	set("unit", "ƿ");
	set_name(jiu[index]);
	
	char msg[255];
	set("long",snprintf(msg, 255,"����һ%s�Ϻõġ�%s�����������ˡ�",querystr("unit"),querystr("name")));
	set_weight(20000);
	
	call_out(do_die, 3600);	
	
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(!strcmp(comm, "get") )
	{
		if(me->query("yuandna/jiu/get"))
		{
			tell_object(me,"��̰��Ŷ���Ȱ������ϵĳ���Ҳ���ٰ���");	
			return 1;
		}
		else
		{
			me->set("yuandna/jiu/get",1);
			return 0;
		}
	}
	return 0;
}

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	if(who == me)
	{
		static char hows[4][255] = {
				"һ������$HIC��$n��$COM���˸��׳��죡",
				"��ü���������ű��Ӱ�$HIC��$n��$COM������ȥ��",
				"����$HIC��$n��$COMϸϸƷ�������Բ����ͰѾƺȵøɸɾ����ˡ�",
				"�����ͷ������$HIC��$n��$COM������������������Ȼ����˹������غ�����ȥ��"
		};
		

		char msg[255];
		message_vision (snprintf(msg, 255,"$N%s",hows[random(4)]), me,this);
		if(me->query("yuandna/jiu/count")>5)
			return notify_fail("��ζ��ᣬ������ʳ�����ޣ���Ҳ�޷����һ���ˡ�");

		me->add("yuandna/jiu/count",1);
		me->del("yuandna/jiu/get");

		int i=random(10);
		int exp,money;
		CContainer * bot;

		if(i>7)
			i=5;
		else
			i=3;

		switch(random(i))
		{
		case 0:
			exp=random(150)+100;
			if(me->query("level")<10)
				exp=1;
			tell_object(me,snprintf(msg, 255,"ϸƷ֮������á�%s��������ζ����������������%d�㾭�顣\n",querystr("name"),exp));
			me->add("combat_exp",exp);
			me->UpdateMe();
			break;
		case 1:
			tell_object(me,"����ôӿ����³�һ�Ž����õĶ�������ϸһ�������ۡ��������ˣ�ԭ����һ�š���Ʊ����\n");
			bot = load_item("yinpiao1");
			if(me->query("level")>10)
				bot->set("value", random(5000)+100);
			else
				bot->set("value", 100);
			bot->move(me);
			break;
		case 2:
			tell_object(me,"ֻ�������ԡ�һ������ҧ����һ��Ӳ���Ķ��������������³���һ����ԭ����һ�龧Ө��͸�ġ���Ƭ����\n");
			load_item("yupian")->move(me);
			break;
		case 3:
			money=random(5000)+1;
			if(me->query("balance")<money )
			{
				if(me->query("balance")>0)
					money=me->query("balance");
				else
					money=0;
			}
			me->add("balance",-money);
			tell_object(me,snprintf(msg, 255,"����Ӵ������Ա���ʳƷ�Ի��˶��ӣ������ҩ�β�������%d�����ӡ�\n",money));
			break;
		case 4:
			exp=random(100)+100;
			if(me->query("level")<10)
				exp=1;
			tell_object(me,snprintf(msg, 255,"��ֻ�������Ժ����������ٶ���������һЩ����������ʧ��%d�㾭�顣\n",exp));
			me->add("combat_exp",-exp);
			me->UpdateMe();
			break;
		case 5:
			tell_object(me,"��Ķ�����ͻȻ������ը����������\n");
			me->add("hp",-me->query("hp")*3/10);
			me->UpdateMe();
			break;
		}
		destruct(this);
		return 1;
	}
	return notify_fail("����ĸ��ԣ���ȻҲ��ð��������ˣ�����Ц����");
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
	{
		CContainer * env = load_room("jy");
		if(!env->query("�"))
			destruct(ob);
	}
	else
		ob->call_out(do_die, 3600);
}
FOOD_END;
