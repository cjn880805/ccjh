//qing_le.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_qing_le);

virtual void create()
{
	set_name("���ֱ���", "qingle biqiu");
	set("long",	"����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺��������������һϮ�ײ��ڱ����ģ��ƺ������ա�");
	
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",young_monk);
	set("foolid",95);
	set("age", 30);
	set("shen_type", 1);
	set("str", 17);
	set("int", 24);
	set("con", 20);
	set("dex", 22);
	set("max_hp", 1050);
	
	set("mp", 350);
	set("max_mp", 350);
	set("mp_factor", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan_yiqi", 30);
	set_skill("dodge", 30);
	set_skill("shaolin_shenfa", 30);
	set_skill("claw", 30);
	set_skill("yingzhua_gong", 30);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("claw", "yingzhua_gong");
	map_skill("parry", "yingzhua_gong");

	prepare_skill("claw", "yingzhua_gong");

	create_family("������", 40, "����");
	set_inquiry("����", ask_me_1);
	set_inquiry("��Ħ��", ask_me_2);

	carry_object("xu_cloth")->wear();
	set("no_huan",1);
};

static char * ask_me_1(CNpc * npc, CChar * me)
{
	if ( DIFFERSTR(me->querystr("family/family_name"), "������"))
		return "���뱾��������������֪�˻��Ӻ�̸��";

    if ( me->query("guilty") > 0 )
		return 	"���۷����䣬������������ܸ��������ͣ�";

    if ( me->query_int() < 30 )
		return 	"���ʲ��������ܽ���ؾ�¥��";
	
	if( me->mini_skill() < 50) 
		return  "�㹦�������������ʸ���ȡ���͡�";
	
    if ( me->query_skill("buddhism",1) < 80 )
		return 	"��ѧϰ�ϳ��书����Ҫ�Ը���𷨻������ǵ�������";

	load_item("allow_letter")->move(me);
	message_vision("$N���һ�����͡�", me);

	return "�ðɣ�ƾ������ͣ�������ɽ���ؾ����¥��ϰ�ϳ��书��";

}

static char * ask_me_2(CNpc * npc, CChar * me)
{
	if ( DIFFERSTR(me->querystr("family/family_name"), "������"))
		return 	"���뱾��������������֪�˻��Ӻ�̸��";

	if( me->mini_skill() < 30) 
		return 	"�㹦��������������ȡ��Ħ�";
	
	load_item("damo_ling")->move(me);
	message_vision("$N���һ���Ħ�", me);

	return "�ðɣ�ƾ�����Ħ�������������ʦ����ս��";
}


NPC_END;
