//shitianjing.h
//code by zwb
//12-16
//inherit F_MASTER;
//inherit F_UNIQUE;

NPC_BEGIN(CNgaibang_shitianjing);

virtual void create()
{
		set_name("ʯ�쾪","shi po tian");

        set("title", "���ְ����");
        set("gender", "����");
        set("age", 20);
        set("long", "����Լ��ʮ���꣬����һ�����õ��·���ȴҲ����ס��һ���Ӣ����");
	 	set("icon",young_man4);

        set("attitude", "peaceful");

        set("str", 25);
        set("int", 35);
        set("con", 25);
        set("dex", 25);

        set("hp", 2000);
        set("max_hp", 6000);
        set("mp", 2000);
        set("max_mp", 2000);
        set("mp_factor", 100);

        set("combat_exp", 1000000);
        set("score", 30000);

        set_skill("force", 100);                 // �����ڹ�
        set_skill("huntian_qigong", 150);        // ��������
        set_skill("unarmed", 100);               // ����ȭ��
        set_skill("xianglong_zhang", 150);       // ����ʮ����
        set_skill("dodge", 100);                 // ��������
        set_skill("xiaoyaoyou", 150);            // ��ң��
        set_skill("parry", 100);                 // �����м�
        set_skill("begging", 50);               // �л�����
//        set_skill("checking", 50);              // ����;˵

        map_skill("force", "huntian_qigong");
        map_skill("unarmed", "xianglong_zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong_zhang");
        set("chat_chance", 8);

        set_inquiry("������","��ȥ����������������������ɡ�");
        set_inquiry("ʯ�м�","�����ҵ��ֵܣ���������Ħ���¡�");
        set_inquiry("����", "ѽ�����������?�����ðɡ�");
        set_inquiry("�����̻��","�������������͵�תת�ɡ�");
        set_inquiry("���Ʒ�����","�����������Ҫ�����ࡣ");
        set_inquiry("����",ask_weiwang );

        carry_object("cloth")->wear();
		set("no_huan",1);
};

virtual char * chat_msg(CChar *player)
{
	switch(random(5))
	{
	case 0:
		return "�������͵���ô�����ˣ�Ҳ��֪�����������������ô���ˡ�";
	case 1:
		return "������������Ҫ�������ߴ��кô�����";
	case 2:
		return "���У��Ҳ����İ��壬��Ҫȥ��������";
	case 3:
		return "�ӣ��ҵ�������ô������һȺ����ڶ��ء�";
	case 4:
		return "���ܸ��������̻����?";
	}
	return "";
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{
	char msg[255];

	npc->say(snprintf(msg,255,"%s�����ڵĽ���������%ld��",player->name(),player->query("weiwang")),player);
	npc->say("ʯ�쾪˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦���������㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ",player);
	npc->say("ʯ�쾪��˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������",player);
	npc->SendMenu(player);

	return "";

}

virtual int recognize_apprentice(CChar * me)
{
	if(DIFFERSTR(me->querystr("party/party_name"), "��ػ�")
		|| me->query("weiwang") < 50)
		return 0;
	
	return 1;
}

virtual int accept_object(CChar * player , CContainer * item)
{
	CContainer * obj;
	if(!player)
		return 0;
	if(!item)
		return 0;
	if(EQUALSTR(item->querystr("id"), "xuanbingbihuo jiu"))
	{
		destruct(item);
		message_vision("ʯ�쾪������˵����λ��磬�Ҹ���ôл���ء�?",player);
		obj=load_item("xuantie");
		obj->move(player);
		return 1;
	}
	return 0;
}
NPC_END;
