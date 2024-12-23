//cai.h ����
//�ز� 2002��12��30

FOOD_BEGIN(CIcai);

virtual void create(int nFlag = 0)
{
	static char cai[45][20]={"Ѭ����","���Ӽ�","������","�廨����","�����ض�","��������","������˿","���ͷ�Ƭ","�������","���ʹ೦","��˿Ѭ��","�Ǵ��Ź�","������˿","������Ϻ","ϸ��ͷ��","���㶬��","��������","��䶹��","���ʸ���","ʱ���߲�","��Ƥ��Ѽ","��������","���Ŷ���","ܽ�ظ���","�ɰ��Ｙ","ܽ��з��","����Ұ��","�����Ｆ","����Ǭ��","��������","���˲ݹ�","�ٻ�Ѽ��","ެ������","��������","��֭ެ��","ɽ��ާ��","�����и�","�Ǵ׺�ź","��ը����","�װ��㴽","���㱫��","��������","�������","�����ƹ�","��˿�㽶"};
	
	int index=random(45);
	set_name(cai[index]);
	
	set_weight(20000);
	set("unit", "��");
	char msg[255];
	
	set("long",snprintf(msg, 255,"����һ�����˴������εġ�%s��",cai[index]));

	call_out(do_die, 3600);	
};


virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(!strcmp(comm, "get") )
	{
		if(me->query("yuandna/cai/get"))
		{
			tell_object(me,"��̰��Ŷ���Ȱ������ϵĳ���Ҳ���ٰ���");	
			return 1;
		}
		else
		{
			me->set("yuandna/cai/get",1);
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
		static char hows[29][255] = {
				"����Ҹ���",
				"��������",
				"��������",
				"�����̵�",
				"��Ϊ�����",
				"��ͷ������",
				"�м����ܵ�",
				"������",
				"�����û��������",
				"ׯ�ϵؿ��Ŵ�ң�Ȼ���¸ҵ�",
				"���������",
				"����������",
				"�������ɵ�",
				"�������ۣ�",
				"ҡͷ���Ե�",
				"����һЦ��",
				"����һ��",
				"���ֱ��ŵ�",
				"��ͷ���Ե�",
				"������Ц����������",
				"�ƿ����ˣ��ںü�ʽ��",
				"��ͷ�����",
				"�˷ܵ���ͷ�󺹣�",
				"��Ƽ��ݵ�",
				"Ĩȥ�۽ǵ��Ứ��",
				"����֣�һ��ţ�",
				"������צ��",
				"ʮ��ǫ���",
				"�ߵ�����ͨ�죬",
		};
		
		static char manners [27][255]  = {
				"��$HIC��$n��$COM�������ﷴ�����˼��£�",
				"��$HIC��$n��$COM�ڵ��Ϸ��ض�⣬",
				"��$HIC��$n��$COM��ǽ���ص�һ���ҿ���",
				"��$HIC��$n��$COM���Ŀ���ϸů��һ�£�",
				"��$HIC��$n��$COM���͹���Ѹ��һը��Ȼ��",
				"������$HIC��$n��$COM��",
				"ʹ��˺��$HIC��$n��$COM��һ��һ���",
				"��$HIC��$n��$COM������Ĩ��һ�����ެ�ѽ���",
				"����$HIC��$n��$COMպ�ź��ĺ��ǣ�",
				"��$HIC��$n��$COM������һ����Σ�",
				"��$HIC��$n��$COM���������Ƭ��ƹϣ�",
				"��$HIC��$n��$COM�ڽ�����һպ��Ʒ��ζ",
				"��$HIC��$n��$COM�����������һ�㣬���е�",
				"��$HIC��$n��$COM�ڿ�ˮ��һ�ݣ�����",
				"��$HIC��$n��$COM�ڻ���һ�ǣ��Ͻ�",
				"��һ�������п�$HIC��$n��$COM��",
				"��������$HIC��$n��$COM",
				"��һ�����˾�����$HIC��$n��$COM�ϣ�",
				"��$HIC��$n��$COM������ˮϴ�øɸɾ�����",
				"��$HIC��$n��$COM�����˰��죬",
				"��$HIC��$n��$COM����һ��ե��˿��",
				"��$HIC��$n��$COM�Ϲ�һ��������ң�",
				"��$HIC��$n��$COM�ʹн���ĩ����һ��",
				"��$HIC��$n��$COM���飬�������ˣ�",
				"��$HIC��$n��$COM�г�С�飬���ϼ����������ȵ����͹��ﳴ�ɹ���$HIC��$n��$COM��",
				"��$HIC��$n��$COM�Ž�������Ͻ��ͺ���С�����ɺ���$HIC��$n��$COM��",
				"��$HIC��$n��$COM�����ڹ��ﵹ�������ͳ�һ���Ǵ�$HIC��$n��$COM��",
		};
		
		static char actions [24][255] = {
				"�ſ�ӣ��С��������ȥ",
				"����Ƭ���촽ҧסֻһ����������ȥ",
				"һ�����������ȥ",
				"��������ƹƹ����һ��",
				"����üͷʹ�ļ��׵س�����ȥ",
				"������һ�ӣ�������Ӱȵ�һ����ס",
				"���������ʹ����һ��",
				"Ӳ��ͷƤ����׽���س�����ȥ",
				"��ર����ü���۵س�����ȥ",
				"�������������ݱ�������ڵ�������ȥ",
				"������ζ����ָ��������ȥ",
				"����û�����첱�ڽŵ�������ȥ",
				"�ʷʵ�����һ��",
				"��������Ͳ����������˶���",
				"һ���ҧ�ų��˲�����",
				"�ſ�Ѫ���ڣ�������������һ��",
				"�Ե��񾭴�����ð����",
				"�Ե������񶫵�����",
				"�Ե������������",
				"�Ե����ߵ��������",
				"�Ե÷����������ذ�",
				"���̻��ʵط�����������ҽ�������ȥ",
				"��������ش����������ֻһ�����������������������ȥ",
				"ʹ�಻���س�����ȥ",
		};
		
		char msg[255];
		message_vision (snprintf(msg, 255,"$N%s%s%s��",hows[random(29)],manners[random(27)],actions[random(24)]), me,this);

		if(me->query("yuandna/cai/count")>10)
			return notify_fail("��ζ��ᣬ������ʳ�����ޣ���Ҳ�޷����һ���ˡ�");

		me->add("yuandna/cai/count",1);
		me->del("yuandna/cai/get");
		
		int i=random(10);
		int exp, money;
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
				if(me->query("balance")>0 )
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
