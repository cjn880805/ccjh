//lu.h
//Lanwood 2000-01-11

NPC_BEGIN(CNtaohua_lu);

virtual void create()
{
	set_name( "½̤��" , "lu tafeng");
	set("gender", "����");
	set("age", 52);
	set("long", "½̤���ǻƵĵ��ĸ�ͽ�ܡ������޽���΢���׷�������Ŀ��࣬˫������");
	set("attitude", "friendly");
	set("class", "scholar");
	set("str", 30);
	set("int", 28);
	set("con", 30);
	set("dex", 30);
	set("chat_chance", 1);
	set("max_hp",4500);
	set("icon",young_man3);
	
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 100);
	set("shen_type",1);
	
	set("combat_exp", 300000);

	set_skill("force", 90);             // �����ڹ�
	set_skill("unarmed", 90);           // ����ȭ��
	set_skill("strike", 90);            // �����Ʒ�
	set_skill("dodge", 70);             // ��������
	set_skill("parry", 90);             // �����м�
	set_skill("sword", 90);             // ��������
	set_skill("leg", 90);

	set_skill("anying_fuxiang", 70);    // ��Ӱ����
	set_skill("luoying_shenzhang", 90);     // ��Ӣ����
	set_skill("xuanfeng_leg", 90);      // ����ɨҶ��
	set_skill("bibo_shengong", 90);     // �̲���
	set_skill("luoying_shenjian", 90);  // ��Ӣ��
	set_skill("literate",90);           // ����ʶ��
	
	map_skill("force"  , "bibo_shengong");
	map_skill("leg", "xuanfeng_leg");
	map_skill("strike" , "luoying_shenzhang");
	map_skill("dodge"  , "anying_fuxiang");
	map_skill("parry"  , "luoying_shenjian");
	map_skill("sword"  , "luoying_shenjian");

	prepare_skill("leg", "xuanfeng_leg");
	prepare_skill("strike", "luoying_shenzhang");
	
	set("jinbing", 10);
	create_family("�һ���", 2, "���� ����ׯ��");
	
	set_inquiry("��а", "��ʦ�˳ƶ�а���Ǻǡ�");
	set_inquiry("����", "����ׯ�������ʦ���������ĸ��֣��˳��϶��");
	set_inquiry("�ϵ�",  "����ʦ˵����ү���ڳ��ҵ��˺��У������ߵơ�");
	set_inquiry("��ؤ",  "��ؤ��л���ؤ��������������ݳ��⡣");
	set_inquiry("�ض�",  "����ʦ���İ�Ů��");
	set_inquiry("���Ϲ�", "��Ҫ�ݷü�ʦ��");
	
	carry_object("cloth")->wear();
	carry_object("changjian");
	carry_object("xuanfeng_book", 1);
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

    if (me->query_dex() < 20)
    {
       say("�����书���������ɽݡ�", me);
       say("������ǰ����һ���һ���ˡ�", me);
	   SendMenu(me);
       return;
    }

    if (me->query("repute") < 1)
    {
       say("�����ڽ�������������������ذɡ�", me);
	   SendMenu(me);
       return;
    }

    if (EQUALSTR(me->querystr("gender"), "����"))
    {
       say("ʦ�������᲻�в�Ů�Ķ����ˣ���Ͽ���ɡ�", me);
	   SendMenu(me);
       return;
    }

    if(EQUALSTR(me->querystr("class"), "bonze"))
    {
       say("ʦ�����ɮ�ֵ��ˣ�������ذɡ�", me);
	   SendMenu(me);
       return;
    }
    if (me->query_skill("literate",1) <= 10)
    {
       say("�һ���ֻ�ն����������ӣ����Ƿ�ȥ������������", me);
	   SendMenu(me);
       return;
    }

    g_Channel.do_emote(this, 0, "smile", 0);
    say(snprintf(msg, 80, "%s�������£���Ŭ�����顣", query_respect(me)));
    command(snprintf(msg, 80, "recruit %ld", me->object_id()));
};

virtual int accept_fight(CChar * me)
{
	char msg[40];
	CContainer * jian = PresentName("changjian", IS_ITEM);
	if(jian)
		command(snprintf(msg, 40, "wield %ld", jian->object_id()));
    return 1;
}

virtual int accept_object(CChar * me, CContainer * obj)
{
	char msg[80], name[40];

	if (query("jinbing") < 0)
	{
        say("�Һ��ۣ����ͷ�������Ͱɡ�", me);
		SendMenu(me);
		return 0;
	}

	strcpy(name, obj->name(1));
	if(! strstr(name, "�����ٵ�ͷ­") &&
	    ! strstr(name, "���պ�����ͷ­") &&
	    ! strstr(name, "������ͷ­") )
	{
        say("������Щ������ʲô�ã�", me);
		SendMenu(me);
		return 0;
	}
	
    say("��������һֱ��ɱ��Щ�𹷣�л������ˡ�", me);
	
	int exp = 20 + random(30);
	
	add("jinbing", -1);
	say(snprintf(msg, 80, "½̤�罱������%ld��ʵս����", exp), me);
	SendMenu(me);
	return 1;
}

NPC_END;
