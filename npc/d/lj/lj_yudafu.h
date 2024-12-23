//lj_yudafu.h	�����
//�ز� 2002��6��1

NPC_BEGIN(CNlj_yudafu);

void create()
{
	set_name("�����","yuda fu");
	set("long", "���������ɶ�����һ�������������ڤ��������");
	set("title", "��ڤ������");
	set("gender", "����");
	set("age", 33);
	set("attitude", "peaceful");
	set("icon",old_man1);
	set("per", 27);
	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set("no_kill",1);

	set("max_hp", 15000);
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 160);

	set("combat_exp", 4500000);
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("claw",300);

	set_skill("wuwen_zhua",300);
	set_skill("guimei_shenfa",300);
	set_skill("wudu_shengong", 300);
    set_skill("tangshoudao", 300);
  
	map_skill("force", "wudu_shengong");
	map_skill("dodge", "guimei_shenfa");
	map_skill("parry", "tangshoudao");
	map_skill("claw", "wuwen_zhua");
	prepare_skill("claw", "wuwen_zhua");
	set("no_talk",1);
	
};

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("lj/renwu4"))
	{
		AddMenuItem("���ּ���", "$0ask1 $1", me);
		if(me->query("lj/renwu4_tiaojian"))
			AddMenuItem("����", "$0ask11 $1", me);
		SendMenu(me);	
		return 1;
	}
	return CNpc::do_talk(me, ask);
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query("lj/renwu4"))
	{
		if(strcmp(comm, "ask1") == 0)
			return do_ask1(me);	
		if(strcmp(comm, "ask11") == 0)
			return do_ask11(me);	
	}
	if(me->query("lj/renwu6") && ! me->query("lj/renwu_lost"))
	{
		me->del("lj/renwu6");
		if(me->query("lj/renwu7"))me->del("lj/renwu7");
		me->set("lj/renwu5",1);
		me->set("lj/renwu55",1);
		say("�����˵�������ϴ��ȷ�Ǵ˴����ɴ����ټ��ˣ��Ѷ��������괺�ٿ���ᣬ��Ҳ��ʱ�������ˣ�", me);
		say("�����˵������������ϣ���������н��������ط������ӡ�", me);
		say("�����˵����Ҫ����һ����ȥ��������һ�ٵ��˺�����Ͷ���ȥ�����ˣ�", me);
		call_out(do_wanxuanhuei, 1);
		SendMenu(me);
	}
	else if(me->query("lj/renwu5"))
	{
		say("�����˵�������ϴ��ȷ�Ǵ˴����ɴ����ټ��ˣ��Ѷ��������괺�ٿ���ᣬ��Ҳ��ʱ�������ˣ�", me);
		say("�����˵������������ϣ���������н��������ط������ӡ�", me);
		say("�����˵����Ҫ����һ����ȥ��������һ�ٵ��˺�����Ͷ���ȥ�����ˣ�", me);
		call_out(do_wanxuanhuei, 1);
		SendMenu(me);
	}
	return CNpc::handle_action(comm, me, arg);
}

int do_ask1(CChar * me)
{
	say("�����˵�����������ּ��ᣬ����ȷʵ֪���ò��٣�ֻҪ���ܰ���һ���£����Կɸ����㡣",  me);
	SendMenu(me);
	me->set("lj/renwu4_tiaojian",1);
	return 1;
}

int do_ask11(CChar * me)
{
	if(!me->query("lj/renwu4_hueifu"))
	{
		say("�����˵��������һ֪���������������괺ĳ���������ܽ���������ȥ�����²�ʤ�м���",  me);
		SendMenu(me);
		if(!me->query("lj/renwu4_xin"))
		{
			CContainer * bot;
			bot = load_item("xin");
			bot->set("long","����һ����ڤ�����������д�����괺Ц�����˵����š�");
			bot->set("value", 0l);
			bot->set("xiaoyuelaoren", 1);
			bot->move(me);
			me->set("lj/renwu4_xin",1);
			tell_object(me, "���õ���һ����ڤ�����������д�����괺Ц�����˵����š���");
		}
	}
	else
	{
		tell_object(me, "�����˵������л��������������");
		tell_object(me, "�����˵�������ϴ��ȷ�Ǵ˴����ɴ����ټ��ˣ��Ѷ��������괺�ٿ���ᣬ��Ҳ��ʱ�������ˣ���");
		tell_object(me, "�����˵������������ϣ���������н��������ط������ӣ�Ҫ����һ����ȥ��������һ�ٵ��˺�����Ͷ���ȥ�����ˣ�");
		me->set("lj/renwu5",1);
		me->del("lj/renwu4");
		me->del("lj/renwu4_tiaojian");
		me->del("lj/renwu4_hueifu");
		me->del("lj/renwu4_xin");
		me->add("combat_exp",500);
		me->UpdateMe();
		tell_object(me, "\n$HIR������ˡ�����������š������񣬻����500��ľ��齱����\n");
		call_out(do_wanxuanhuei, 1);
	}
	return 1;
}


static void do_wanxuanhuei(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env ;
	CNpc * wanxuanhuei;
	int i,j;
	env = load_room("���괺����");
	if(!env->query("lj/wanxuanhuei"))
	{
		env->set("lj/wanxuanhuei",1);
		wanxuanhuei = load_npc("lj_shuxia");
		wanxuanhuei->move(env);

		env = load_room("���괺ѩ�޷�");
		if(!env->query("lj/wanxuanhuei"))
		{
			env->set("lj/wanxuanhuei",1);
			wanxuanhuei = load_npc("lj_shuxia");
			wanxuanhuei->move(env);
		}
		env = load_room("���괺ѩ����");
		j=random(6)+6;
		for(i=0;i<j;i++)
		{
			wanxuanhuei = load_npc("lj_shuxia");
			wanxuanhuei->move(env);
		}
		env = load_room("���괺�ش���");
		j=random(6)+6;
		for(i=0;i<j;i++)
		{
			wanxuanhuei = load_npc("lj_shuxia");
			wanxuanhuei->move(env);
		}
		env = load_room("���괺���޷�");
		j=random(6)+6;
		for(i=0;i<j;i++)
		{
			wanxuanhuei = load_npc("lj_shuxia");
			wanxuanhuei->move(env);
		}
		env = load_room("���괺�ó���");
		if(env->querymap("lj"))env->del("lj");
		j=11;
		static char ljdongzhu[11][20]={"lj_wulaoda","lj_duanmufang","lj_ganshuangqing","lj_hefueren","lj_hedongzhu",
			"lj_andongzhu","lj_qingdaozhu","lj_qudaozhu","lj_yundaozhu","lj_zhuyadaguai","lj_zhuyaerguai"};

		for(i=0;i<j;i++)
		{
			wanxuanhuei = load_npc(ljdongzhu[i]);
			wanxuanhuei->move(env);
		}
	}

}

NPC_END;




