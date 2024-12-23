//duanzc.h
//Lanwood 2000-01-05

ZUSHI_BEGIN(CNdali_duanzc);

virtual void create()
{
	set_name("������", "duan zhengpu");
	set("title",  "����������" );
	set("long", "�����Ǵ�������������������̫�ܣ��������İ���ʥ�֡�");
	set("gender", "����");
	set("icon", young_man4);

	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	
	set("max_hp", 6600);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	set("combat_exp", 1000000);
	set("score", 300000);

    set_skill("force", 150);
    set_skill("dodge", 150);
    set_skill("parry", 150);
    set_skill("cuff", 140);
    set_skill("strike", 150);
    set_skill("sword", 150);
    set_skill("staff", 150);
    set_skill("finger", 120);
	set_skill("kurong_changong", 150);
    set_skill("tiannan_step", 150);
    set_skill("jinyu_quan", 130);
    set_skill("wuluo_zhang", 150);
    set_skill("duanjia_sword", 150);
    set_skill("sun_finger", 100);
    set_skill("lm_shangyang", 100);
	set_skill("literate", 100);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("finger", "sun_finger");
	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("parry", "sun_finger");
	map_skill("sword", "duanjia_sword");
	map_skill("staff", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");

	carry_object("cloth")->wear();
	add_money(5000);

	create_family("����μ�",18,"������");
	set("no_huan",1);
};

virtual void attempt_apprentice(CChar * me)
{
	char oldtitle[40];
	char msg[80];
	
	strncpy(oldtitle, me->querystr("title"), 40)[39] = 0;

	if (me->query_skill("kurong_changong",1) < 100 )
	{
		say("��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɡ�", me);
		SendMenu(me);
		return;
	}

	if (me->query("repute") < 10000  ) 
	{
		say("�Ҵ�����������������壬����ذɣ�", me);
		SendMenu(me);
		return;
	}

	if (strstr(oldtitle, "������������")) 
	{
		say("�ܺã���Ȼ���������͵�����Ϊ����");
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("title", oldtitle);
		me->UpdateMe();
	}
	else
	{
		say("���Ǻ��ˣ���˴󵨣���ð�Ҹ������ͣ�", me);
		SendMenu(me);
		return;
	}
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	if (DIFFERSTR((who->environment())->querystr("base_name"), "�������������" ))
		return notify_fail("�����������");
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s���˵�ͷ�����������͹����İ�����",name(1)));
		tell_object(who, "\n$YEL��������渣���ھ�Ѻ�˰��ڵ�����");
		tell_object(who, snprintf(msg, 255, "$YEL�����%d�ľ��齱������������������%d��",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)ѹ�˰��ڳɹ��������%d�ľ��齱������������������%d�㣡", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}
	return 0;
}

ZUSHI_END;
