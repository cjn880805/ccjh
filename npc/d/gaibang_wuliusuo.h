//wuliusuo.h
//code by zwb
//12-16
//inherit F_MASTER;
//inherit F_UNIQUE;

NPC_BEGIN(CNgaibang_wuliusuo);

virtual void create()
{
	set_name("������","wu liu suo");

	set("title", "��ػ��˳������");
	set("nickname", "Ѫ����ؤ");
	set("gender", "����");
	set("age", 50);
	set("long","����Ͻл����������������ġ�Ѫ����ؤ������������������������ڹپӹ㶫�ᶽ֮ʱ������һʡ�ر������˲����õ�Ȱ�����Ĵ淴�帴��֮־��������ػᣬ��ְ��˳��������");
 	set("icon",old_man1);

	set("attitude", "peaceful");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("hp", 1500);
	set("max_hp", 4500);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 100);
	
	set("combat_exp", 150000);
	set("score", 30000);
	
	set_skill("force", 95);			// �����ڹ�
	set_skill("huntian_qigong", 90);	// ��������
	set_skill("unarmed", 90);		// ����ȭ��
	set_skill("xianglong_zhang", 85);	// ����ʮ����
	set_skill("dodge", 90);			// ��������
	set_skill("xiaoyaoyou", 95);		// ��ң��
	set_skill("parry", 85);			// �����м�
	set_skill("begging", 50);		// �л�����
//	set_skill("checking", 50);		// ����;˵
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	set("chat_chance", 3);

	set_inquiry("��Զ��","����ܶ����ɲ����װ���");
	set_inquiry("��ػ�","ֻҪ��Ӣ�ۺú���������������ػ�");
	set_inquiry("���","ֻҪ��������ػᣬ��������и�λ����ѧ�书��");
    set_inquiry("���帴��","ȥҩ�̺͹ײĵ���ϸ���ưɣ�");
    set_inquiry("����",ask_weiwang );

	carry_object("cloth")->wear();
};

virtual char * chat_msg(CChar * me)
{
	switch(random(5))
	{
	case 0:
		return "��������Ȼ�ſ������������������߽��ߣ���ǻ�ߺ���˭�ԣ���������";
	case 1:
		return "���������������ζ������¸����̡������Դ��У�������Զ��";
	case 2:
		return "������������Ҫ�������ߴ��кô�����";
	case 3:
		return "������ͻȻ˵��: �ɰض�֦�����ң��нں黪����ͤ";
	case 4:
		return "������ͻȻ˵��: ������ǰ����Ը�����帴���Һ�Ӣ��";
	}
	return "";
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{

	char msg[255];

	npc->say(snprintf(msg,255,"��Ľ���������%ld",player->query("weiwang")),player);
	npc->say("������˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦���������㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ",player);
	npc->say("��������˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������",player);
	npc->SendMenu(player);

	return "";

}

virtual int recognize_apprentice(CChar * player)
{
	if(DIFFERSTR(player->querystr("party/party_name"), "��ػ�"))
		return 0;
	
	return 1;
}

NPC_END;