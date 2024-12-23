//qu.h
//Lanwood 2000-01-11

ZUSHI_BEGIN(CNtaohua_huang);

virtual void create()
{
	set_name("���Ϲ�", "huang laoguai");
	set("gender", "����");
	set("age", 42);
	set("long",  "�������һ����������ºö�ȫ�ɼ��ġ�");
	set("icon",young_man2);
	
	set("attitude", "peaceful");
	set("class", "scholar");
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("chat_chance", 10);
	set("chat_chance_combat", 15);

	set("hp",21000);
	set("max_hp",21000);
	set("mp", 16500);
	set("max_mp", 16500);
	set("mp_factor", 250);
	
	set("combat_exp", 60000000);
    
	set_skill("force", 280);             // �����ڹ�
	set_skill("claw", 200);              // ����צ��
	set_skill("hand", 220);              // �����ַ�
	set_skill("finger", 240);            // ����ָ��
    set_skill("unarmed", 280);           // ����ȭ��
    set_skill("strike", 220);            // ����ȭ��
	set_skill("leg", 400);	           // ����ȭ��
    set_skill("dodge", 280);             // ��������
    set_skill("parry", 280);             // �����м�
    set_skill("sword", 300);             // ��������

    set_skill("anying_fuxiang", 280);    // ��Ӱ����
    set_skill("tanzhi_shentong", 300);   // ��ָ��ͨ
    set_skill("xuanfeng_leg", 280);      // ����ɨҶ��
    set_skill("luoying_shenzhang", 280);     // ��Ӣ����
	set_skill("bibo_shengong", 300);     // �̲���
    set_skill("luoying_shenjian", 280);  // ��Ӣ��
    set_skill("yuxiao_jianfa", 300);       // ���｣��
    set_skill("lanhua_shou", 280);       // ������Ѩ��
    set_skill("qimen_wuxing",300);       // ��������
    set_skill("literate", 300);           // ����ʶ��
	set_skill("count",150);              // ��������
	
    map_skill("force"  , "bibo_shengong");
    map_skill("finger" , "tanzhi_shentong");
    map_skill("hand"   , "lanhua_shou");
	map_skill("unarmed", "luoying_shenzhang");
    map_skill("strike", "luoying_shenzhang");
	map_skill("leg", "xuanfeng_leg");
    map_skill("dodge"  , "anying_fuxiang");
    map_skill("parry"  , "tanzhi_shentong");
    map_skill("sword"  , "tanzhi_shentong");
	
	prepare_skill("finger", "tanzhi_shentong");
	prepare_skill("hand", "lanhua_shou");
	
	create_family("�һ���", 1, "����");
	
	set_inquiry("�ض�", "�ض��ɻ������ˣ������ֵľ��ǡ����˭������÷����");
	set_inquiry("�����澭", "�ҰѾ����澭����һ�������ܵĵط���");
	
	carry_object("bluecloth")->wear();
	carry_object("yuxiao");

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("no_huan",1);
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "���Ϲ�̾�˿����������� �����ض�������ĺ��ӣ���С��û�������";
	case 1:
        return "���Ϲֵ�ͷ��˼����Ȼ���";
	}

	return 0;
}

virtual char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("force powerup", 1);
		break;
	case 1:
		perform_action("hand fuxue", 1);
		break;
	case 2:
		perform_action("finger hui", 1);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

    if (me->query_dex() < 35)
    {
       say("�����书���������ɽݡ�", me);
       say("������ǰ����һ���һ���ˡ�", me);
	   SendMenu(me);
       return;
    }

    if (me->query_int() < 35)
    {
       say("�����书�������Ǵ�����", me);
       say("������ǰ����һ���һ���ˡ�", me);
	   SendMenu(me);
       return;
    }

	if (me->query("repute") > 10000 || me->query("repute") < -10000 )
    {
       say("���һ����������������ڽ������Ѿ��������α������һ�����", me);
	   SendMenu(me);
       return;
    }

    if (EQUALSTR(me->querystr("gender"), "����"))
    {
       say("�������᲻�в�Ů�Ķ����ˣ����Ȼ������", me);
	   SendMenu(me);
	   kill_ob(me);
       return;
    }

    if(EQUALSTR(me->querystr("class"), "bonze"))
    {
       say("�����ɮ�ֵ������Ȼ������", me);
	   SendMenu(me);
	   kill_ob(me);
       return;
    }

    if (me->query_skill("bibo_shengong",1) <= 150)
    {
       say("���Ź��򻹲���ʵ���������ң�", me);
	   SendMenu(me);
       return;
    }
   
    g_Channel.do_emote(this, 0, "smile", 0);
    say(snprintf(msg, 80, "�ܺã��ܺá�", query_respect(me)));
    command(snprintf(msg, 80, "recruit %ld", me->object_id()));
};


virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "�һ���Ĺ��" ))
		return notify_fail("�����������");
	char msg[255];
	if (ob->query("is_task")==2)
	{
		command("thank");
		who->set("teapot/yangguo",1);
		tell_object(who,"���Ϲ�͵͵�����㣺Сʱ����ˣ��ʱ���ⶫ�����С�ף�����������ʮ������");
		tell_object(who,"���Ϲ�͵͵�����㣺������һ���ʵ۵����ܣ�1110101000010110101��");
		DESTRUCT_OB(ob, "huang::accept_object");
		return 1;
	}
	else if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
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
