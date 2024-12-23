//dy_master.h
//lanwood 2001-11-04

NPC_BEGIN(CNdy_master);

void create()
{
	set_name("˿·Ʈ��", "piao miao");
	
	set("gender", "Ů��");
	
	set("icon", young_woman1);
	set("level", 20);
	
	set("max_hp", 12000);
	set("max_mp", 3000);
	set("mp_factor", 70);
	
	set("combat_exp", 952800);
	
	set("cast_chance", 20);
	set("nkgain", 1);
	
	set("str", 34);
	set("con", 35);
	set("int", 35);
	set("dex", 22);
	
	set_skill("changquan", 206);
	set_skill("cuff", 206);
	set_skill("guimei_shenfa", 206);
	set_skill("dodge", 206);
	set_skill("hunyuan_yiqi", 206);
	set_skill("force", 206);
	
	map_skill("cuff", "changquan");
	map_skill("dodge", "guimei_shenfa");
	map_skill("force", "hunyuan_yiqi");
	
	prepare_skill("cuff", "changquan");
	
	set("apply/armor", 120);
	set("apply/damage", 150);
	
	set("task_open", 1);	//���񿪷�
	set("no_kill", 1);
}

char * chat_msg_combat()
{
	perform_action("force recover", 0);
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(query("task_open"))
	{
		AddMenuItem("Ľ����Ө", "$0getinfo $1", me);
		AddMenuItem("ɱ�˷Ż�", "$0askquest $1", me);
		AddMenuItem("�Ҳ�����", "$0report $1", me);
		AddMenuItem("����ʧ��", "$0fail $1", me);
		SendMenu(me);	
	}
	else
	{
		say("�����������Ŀ�����ԭ������˳��ٲ��ɣ����˰��ˡ�", me);
		SendMenu(me);
	}	
	return 1;
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(query("task_open"))
	{
		if(strcmp(comm, "getinfo") == 0)
			return do_18dy(me);
		if(strcmp(comm, "askquest") == 0)
			return do_kill(me);	
		if(strcmp(comm, "report") == 0)
			return do_r(me);
		if(strcmp(comm, "fail") == 0)
			return do_f(me);
	}
	
	return CNpc::handle_action(comm, me, arg);
}

int do_18dy(CChar * me)
{
	
	say("����Ľ���������Ѽ����������ؼ�����������������ꡣ"
		"���ǵĵ�ʮ��������Ľ����ӨͻȻ����Ӣ��������������Ӣ��"
		"�ۻ����Ӣ��¥�����Ľ�����ҵĸ�����ѧ�ؼ���", me);
	say("��˵Ľ�����ұ����и�������ʧ���������ѧ�䱾��"
		"�л���ȥĽ�����Ҳν��ؼ����Խ����е������˶��Զ��м�����ջ�����", me);
	say("Ӣ��¥�ǽ����ڵ��µ�һ���Ӵ�Ļ��أ���˵��ʮ�˲㡣"
		"ÿһ�㶼����Ž������ľ������ĸ�����ѧ�ؼ���", me);
	say("ÿ�춼�кܶ��˱��ͽ�Ӣ��¥��"
		"����һ�������棬�ͱ�������������������һ������������ϰ��ѧ��"
		"Ҳ����Ϊ����һ���ؼ�������ɱ¾��", me);
	say("�������˲�Ը�������ӵ��ѧϰ�ؼ��Ļ��ᣬ"
		"���Ժ����߽����������ɱ�����ڵ�Ӣ��¥�ѱ�����˼������"
		"���ǣ�ÿ�����Ӣ��¥������Ȼ�����޼���", me);
	say("Ӣ��¥��ʣ�µ����Ѿ�ħ�Դ�ʧȥ�����ǣ��侫����"
		"��Ľ����Ө��ȫ�����ˡ�Ľ����Ө�����������Ե�̰��"
		"��һ�����Ļ�����ԭ���֣��Դﵽ���������������롣", me);
	say("������ֹĽ����Ө����ı��", me);
	SendMenu(me);
	
	if(!me->query("18dy/task"))
	{	
		say("����Ľ���������Ѽ����������ؼ�����������������ꡣ"
			"���ǵĵ�ʮ��������Ľ����ӨͻȻ����Ӣ��������������Ӣ��"
			"�ۻ����Ӣ��¥�����Ľ�����ҵĸ�����ѧ�ؼ���", me);
		say("��˵Ľ�����ұ����и�������ʧ���������ѧ�䱾��"
			"�л���ȥĽ�����Ҳν��ؼ����Խ����е������˶��Զ��м�����ջ�����", me);
		say("Ӣ��¥�ǽ����ڵ��µ�һ���Ӵ�Ļ��أ���˵��ʮ�˲㡣"
			"ÿһ�㶼����Ž������ľ������ĸ�����ѧ�ؼ���", me);
		say("ÿ�춼�кܶ��˱��ͽ�Ӣ��¥��"
			"����һ�������棬�ͱ�������������������һ������������ϰ��ѧ��"
			"Ҳ����Ϊ����һ���ؼ�������ɱ¾��", me);
		say("�������˲�Ը�������ӵ��ѧϰ�ؼ��Ļ��ᣬ"
			"���Ժ����߽����������ɱ�����ڵ�Ӣ��¥�ѱ�����˼������"
			"���ǣ�ÿ�����Ӣ��¥������Ȼ�����޼���", me);
		say("Ӣ��¥��ʣ�µ����Ѿ�ħ�Դ�ʧȥ�����ǣ��侫����"
			"��Ľ����Ө��ȫ�����ˡ�Ľ����Ө�����������Ե�̰��"
			"��һ�����Ļ�����ԭ���֣��Դﵽ���������������롣", me);
		say("������ֹĽ����Ө����ı��", me);
		SendMenu(me);
		
		me->set("18dy/level", 1);		//����ʯͷ���������ɡ�
		me->set("18dy/task", 1);		//��һ������
	}
	return 1;
}

//18����
int do_kill(CChar * me)
{
	if(!me->query("18dy/task"))
	{	
		me->set("18dy/level", 1);	//��һ��
		me->set("18dy/task", 1);	//��һ������
	}
	
	if (me->query("18dy/level") != me->query("18dy/task") 
		&& me->query("18dy/task") > 0)
		return notify_fail("˿·Ʈ��˵���㲻�����������������");	
	
	if (me->query_temp("18dy/finish") )
		return notify_fail("˿·Ʈ��˵����������ҵ�����Ӧ�����ұ���ġ�");
	
	if (me->is_busy())
		return notify_fail("�����ں�æ������");
	
	if (me->query_temp("18dy/master"))			//�����������ظ�������ܡ�
	{
		char msg[255];
		message_vision(snprintf(msg, 255, "$RED�Ҳ�������Ǳ��%s��ɱ��%s���������˻�����ȥ��$COM",me->querystr_temp("18dy/env"),me->querystr_temp("18dy/kill_name")), me);
		return 1;
	}
	
	char msg[255];
	CNpc * tn;
	
	switch(me->query("18dy/task"))
	{
	case 1:
		tn = load_npc("dy2_monster");
		me->set_temp("18dy/env", "��Ȫ֮·");
		break;
	case 2:
		tn = load_npc("dy3_monster");
		me->set_temp("18dy/env", "�κ���");
		break;
	case 3:
		tn = load_npc("dy4_monster");
		me->set_temp("18dy/env", "���Ź�");
		break;
	case 4:
		tn = load_npc("dy5_monster");
		me->set_temp("18dy/env", "�������");
		break;
	case 5:
		tn = load_npc("dy6_monster");
		me->set_temp("18dy/env", "��ɽ����");
		break;
	case 6:
		tn = load_npc("dy7_monster");
		me->set_temp("18dy/env", "��ɳ����");
		break;
	case 7:
		tn = load_npc("dy8_monster");
		me->set_temp("18dy/env", "��ʺ����");
		break;
	case 8:
		tn = load_npc("dy9_monster");
		me->set_temp("18dy/env", "�������");
		break;
	case 9:
		tn = load_npc("dy10_monster");
		me->set_temp("18dy/env", "�𺣵���");
		break;
	case 10:
		tn = load_npc("dy11_monster");
		me->set_temp("18dy/env", "��������");
		break;
	case 11:
		tn = load_npc("dy12_monster");
		me->set_temp("18dy/env", "��������");
		break;
	case 12:
		tn = load_npc("dy13_monster");
		me->set_temp("18dy/env", "��ɽ����");
		break;
	case 13:
		tn = load_npc("dy14_monster");
		me->set_temp("18dy/env", "��������");
		break;
	case 14:
		tn = load_npc("dy15_monster");
		me->set_temp("18dy/env", "��Ƥ����");
		break;
	case 15:
		tn = load_npc("dy16_monster");
		me->set_temp("18dy/env", "���Ե���");
		break;
	case 16:
		tn = load_npc("dy17_monster");
		me->set_temp("18dy/env", "��������");
		break;
	case 17:
		tn = load_npc("dy18_monster");
		me->set_temp("18dy/env", "��ĥ����");
		break;
	case 18:
		tn = load_npc("dy19_monster");
		me->set_temp("18dy/env", "������");
		break;
	case 19:
		tn = load_npc("dy20_monster");
		me->set_temp("18dy/env", "�������");
		break;
	case 20:
		tn = load_npc("dy21_monster");
		me->set_temp("18dy/env", "��ͭ����");
		break;
	case 21:
		tn = load_npc("dy22_monster");
		me->set_temp("18dy/env", "���ǵ���");
		break;
	}
	message_vision(snprintf(msg, 255, "$HIG�����Ǳ��$HIR%s$HIG��ɱ��%s��$COM", me->querystr_temp("18dy/env"),tn->name()), me);
	me->set_temp("18dy/kill", tn->querystr("id"));		//����NPC��id��
	me->set_temp("18dy/kill_name", tn->querystr("name"));		//����NPC���������֡�
	me->set_temp("18dy/master", 1);							//������ı�ǡ�
	destruct(tn);
	
	return 1;
}

int do_r(CChar * me)
{
	
	if (me->query("18dy/boss") == 1)
	{
		me->del("18dy/boss");			//ȥ��ɱ��BOSS�ļ�¼��
		me->add("18dy/task", 1);		//�����ȥ��һ��ɱ���ˡ�
		
		me->delete_temp("18dy");				//�����һ�ص���Ϣ��
		
		reward_exp(me);					//����3�ξ��顣	
		reward_exp(me);	
		reward_exp(me);	
		
		return notify_fail("˿·Ʈ��˵����ɱ��BOSS���ã��ã��ã������ȥ��һ�������ˡ�");
	}
	
	if (!me->query_temp("18dy/finish") )
		return notify_fail("˿·Ʈ��˵����ɱ����Ҫ��ɱ������ô��");
	
	message_vision("$HIG˿·Ʈ������ã��ã�$N�����������μ�޵��������ٽ�������",me);
	
	reward_exp(me);	
	
	me->delete_temp("18dy/finish");
	
	if (me->query_temp("18dy/run") >= (5+me->query("18dy/level")) )
	{
		me->set_temp("18dy/run", 0l);
	}
	
	me->add_temp("18dy/run", 1);							//�����������Ĵ�����
	me->delete_temp("18dy/master");							//��������¼��
	me->delete_temp("18dy/kill_name");	
	me->delete_temp("18dy/kill");	
	me->delete_temp("18dy/env");	
	me->add("18dy/num", 1);								//�����������Ĵ�����
	
	me->start_busy(6);
	
	if (me->query("18dy/num") >= (81+me->query("18dy/level")*9))						//�������Ĵ�����
	{
		me->add("18dy/level", 1);
		return notify_fail("˿·Ʈ��˵�������ȥ��һ���ˡ�");
	}
	
	return 1;
}

void reward_exp(CChar * me)
{
	char msg[255], tmp[80];
	LONG exp = me->query("18dy/task");		
	
	exp = 300 + exp * 50;
	
	exp = exp + random(me->query_temp("18dy/run") * exp / 30);	//�Ѷ�ϵ��
	
	exp = (random(exp) + exp) / 2;
	
	me->add("combat_exp", exp);
	tell_object(me, snprintf(msg, 255, "$HIC������%s�㾭�飡", chinese_number(exp, tmp)));
	
	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "%s�������%sɱ%s�����񣬻��%d���顣", me->name(1), me->querystr_temp("18dy/env"),me->querystr_temp("18dy/kill_name"),  exp));
	
	me->FlushMyInfo();
}

int do_f(CChar * me)
{
	
	if (me->query_temp("18dy/master") == 0)
		return notify_fail("$HIR˿·Ʈ���ŭ�������û�����������Դ����ƻ������Դ��пӡ�$COM");
	
	if (me->query_temp("18dy/finish") == 1)
		return notify_fail("$GRN˿·Ʈ�첻�⣺�������ȴ��Ҫ�ر����ѵ�����СŮ��ô��$COM");
	
	if (me->query_temp("18dy/master") == 1)
	{
		me->delete_temp("18dy/finish");		//������Ҵ�������δ���״̬��
		me->delete_temp("18dy/master");		//��������¼��
		me->delete_temp("18dy/run");		//��������������Ĵ�����
		
		me->delete_temp("18dy/kill");		//�������NPC�����ơ�
		me->delete_temp("18dy/kill_name");	//�������NPC���������֡�
		
		if (me->query("18dy/num") < 1)
		{
			me->set("18dy/num", 1);
		}
		
		me->add("18dy/num", -1);			//�������Ĵ�����
		
		me->start_busy(30);					//��ҿ�ʼæ��30�롣
		
		return notify_fail("˿·Ʈ������̾����������Ȼ����������СŮҲ���ڼ���ǿ��");
	}
	return 1;
}


NPC_END;