//lj_shangtugong.h	������
//�ز� 2002��6��1

NPC_BEGIN(CNlj_shangtugong);

void create()
{
	set_name("������","shangtu gong");
	set("long", "�����ͷ���ߣ�һ�Ŵ��Դ���ͺͺ�أ����ͷ��Ҳ�ޣ�������Ѫ��ԶԶ��ȥ������һ����Ѫ��һ��");
	set("title", "���׶�����");
	set("gender", "����");
	set("age", 43);
	set("attitude", "peaceful");
	set("icon",old_man1);
	set("per", 11);
	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);

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
	set("no_huan",1);
	
};

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("lj/renwu1"))
	{
		AddMenuItem("���ּ���", "$0ask1 $1", me);
		if(me->query("lj/renwu1_tiaojian"))
			AddMenuItem("����", "$0ask11 $1", me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query("lj/renwu1"))
	{
		if(strcmp(comm, "ask1") == 0)
			return do_ask1(me);	
		if(strcmp(comm, "ask11") == 0)
			return do_ask11(me);	
	}
	if(me->query("lj/renwu2"))
	{
		say("������˵������λ��������֮��ȷ�д��ţ�˵�����������չ���ʧ���ˡ�", me);
		say("������˵��������������Թ�ԣ��ʶ�����һ��ۼ�ɱ�����չ�������ЩС��Ƥ���������Ľ�ҩ��", me);
		say("������˵��������ҵ��ر�������������֤����˵����١�", me);
		SendMenu(me);
	}
	return CNpc::handle_action(comm, me, arg);
}

int do_ask1(CChar * me)
{
	say("������˵�����������ּ��ᣬ����ȷʵ֪���ò��٣�ֻҪ���ܰ���һ���£����Կɸ����㡣",  me);
	SendMenu(me);
	me->set("lj/renwu1_tiaojian",1);
	return 1;
}
int do_ask11(CChar * me)
{
	say("������˵������һ������������ö�֮����Ϊ�����������Ϊ���ҵ�һ�����ޱ����룬�Ϸ�м�֮����Ȼ�޻���˵��",  me);
	SendMenu(me);
	me->set("lj/renwu1_zheng",1);
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(!who->query("lj/renwu1_zheng"))	return 0;
	if(DIFFERSTR(ob->querystr("name"), "������") )	return 0;
	destruct(ob);
	tell_object(who, "������˵������λ��������֮��ȷ�д��ţ�˵�����������չ���ʧ���ˡ�");
	tell_object(who, "������˵��������������Թ�ԣ��ʶ�����һ��ۼ�ɱ�����չ�������ЩС��Ƥ���������Ľ�ҩ��");
	tell_object(who, "������˵��������ҵ��ر�������������֤����˵����١�");
	who->set("lj/renwu2",1);
	who->del("lj/renwu1");
	who->del("lj/renwu1_tiaojian");
	who->del("lj/renwu1_zheng");
	who->add("combat_exp",500);
	who->UpdateMe();
	tell_object(who, "\n$HIR������ˡ���������Ѱ�ұ����롱�����񣬻����500��ľ��齱����\n");
	return 1;
}

NPC_END;




