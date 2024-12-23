//qu.h
//Lanwood 2000-01-11

NPC_BEGIN(CNtaohua_qu);

virtual void create()
{
	set_name("���ɷ�", "qu lingfeng");
	set("gender", "����");
	set("age", 46);
	set("long",  "���ɷ��ǻ��ϹֵĴ�ͽ�ܣ�Ҳ�ǻ��Ϲ�������ͽ�������Ի��Ϲ�һ�����Ĺ������������Ը�Ź֣�������ʦ����а����");
	set("icon",young_man2);
	
	set("attitude", "peaceful");
	set("class", "scholar");
	set("str", 30);
	set("int", 40);
	set("con", 35);
	set("dex", 25);
	set("chat_chance", 1);
	set("max_hp",5400);
	
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 100);
	
	
	set("combat_exp", 1200000);

	set_skill("force", 160);             // �����ڹ�
	set_skill("unarmed", 160);           // ����ȭ��
	set_skill("strike", 150);            // �����Ʒ�
	set_skill("dodge", 160);             // ��������
	set_skill("parry", 160);             // �����м�
	set_skill("sword", 150);             // ��������
	set_skill("leg", 150);

	set_skill("anying_fuxiang", 160);    // ��Ӱ����
	set_skill("luoying_shenzhang", 160);     // ��Ӣ����
	set_skill("xuanfeng_leg", 160);      // ����ɨҶ��
	set_skill("bibo_shengong", 160);     // �̲���
	set_skill("luoying_shenjian", 160);  // ��Ӣ��
	set_skill("literate",150);           // ����ʶ��
	
	map_skill("force"  , "bibo_shengong");
	map_skill("unarmed", "xuanfeng_leg");
	map_skill("strike" , "luoying_shenzhang");
	map_skill("dodge"  , "anying_fuxiang");
	map_skill("parry"  , "luoying_shenjian");
	map_skill("sword"  , "luoying_shenjian");

	prepare_skill("leg", "xuanfeng_leg");
	prepare_skill("strike", "luoying_shenzhang");
	
	create_family("�һ���", 2, "����");
	
	set_inquiry("��а", "��ʦ�˳ƶ�а���Ǻǡ�");
	set_inquiry("����", "����ׯ�������ʦ���������ĸ��֣��˳��϶��");
	set_inquiry("�ϵ�",  "����ʦ˵����ү���ڳ��ҵ��˺��У������ߵơ�");
	set_inquiry("��ؤ",  "��ؤ��л���ؤ��������������ݳ��⡣");
	set_inquiry("�ض�",  "����ʦ���İ�Ů��");
	set_inquiry("���Ϲ�", "��Ҫ�ݷü�ʦ��");
	
	carry_object("cloth")->wear();
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "���ɷ�˵������ʦ���۰�Сʦ�ã�������⬼�һֱ��Сʦ�ô��š���";
	case 1:
        return "���ɷ����������˵����������һ����ˣ����򵥣���";
	}

	return 0;
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

    if (me->query_skill("bibo_shengong",1) <= 30)
    {
       say("����һ���֮ǰûȥ��½ʦ���Ƕ�ô��", me);
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

NPC_END;
