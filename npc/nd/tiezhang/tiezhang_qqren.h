// qqren.c ��ǧ��
//sound 2001-07-11

NPC_BEGIN(CNtiezhang_qqren);

virtual void create()
{
	set_name("�ðٳ�", "qiu qianren");
	set("nickname", "����ˮ��Ư");
	set("long", 
		"����������������ư�İ���-����ˮ��Ư�ðٳߡ�\n"
		"����һ��������ͷ�����Ƹ���������ֻ���һ�Ѵ����ȡ�\n");
	set("gender", "����");
	set("age", 60);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 28);
	set("dex", 35);
	set("icon",old_man1);
	
	set("max_hp", 4000);
	set("hp", 4000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 200);
	set("combat_exp", 1000000);
	set("score", 400000);
	set_skill("hammer",100);
	set_skill("tiexue_hammer",180);
	set_skill("force", 160);
	set_skill("guiyuan_tunafa", 200);
	set_skill("dodge", 160);
	set_skill("shuishangpiao", 200);
	set_skill("strike", 180);
	set_skill("tiezhang_zhangfa", 200);
	set_skill("parry", 160);
	set_skill("literate", 100);
	set_skill("axe", 160);
	set_skill("duanyun_fu", 200);
	map_skill("hammer", "tiexue_hammer");
	
	map_skill("force", "guiyuan_tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("strike", "tiezhang_zhangfa");
	map_skill("parry", "tiezhang_zhangfa");
	prepare_skill("strike", "tiezhang_zhangfa");
	
	create_family("���ư�", 14, "����");

	set_inquiry("����", "�Ϸ���ǡ�����ˮ��Ư���ðٳߣ������Ϸ�������ʲô��ô��");
	set_inquiry("����", "����������ư����̳���ڣ�����û�£���Ҫ�Ĵ����ߣ�����ɱ��֮��������");
/*
	set("inquiry", ([
		"�Ϲٽ���" : (: ask_qiubai :),
		]));
*/	
	carry_object("cloth")->wear();
}
/*
void attempt_apprentice(object me)
{
	if ((int)me->query("shen") > -10000) {
		command("hehe");
		command("say ����ǧ��ɲ����Ĵ����������ͽ�ܡ�");
		return;
	}
	command("say �ðɣ��Ҿ��������ˡ�ϣ������������񹦣���֮������");
	command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_available", -1);
}
int ask_qiubai()
{
	say("������ʦ��������ʮ�����������ȹ�����֮�����ж�ͼ������ȫ\n"
		"���书�������ܡ���ϧʮ��ǰ�����ں�������Χ������������\n");
	return 1;
}
*/
NPC_END;