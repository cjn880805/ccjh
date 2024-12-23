//qqzhang.c ��ǧ��
//sound 2001-07-11

NPC_BEGIN(CNtiezhang_qqzhang);

virtual void create()
{
	set_name("��ǧ��", "qiu qianzhang");
	set("long", 
		"����һ��������ͷ�����Ƹ�������㴩��Ь�����ֻ���һ�Ѵ����ȡ�\n"
		"���������ͻ������ı��顣\n");
	set("gender", "����");
	set("age", 60);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 30);
	set("con", 26);
	set("dex", 25);
//	set("env/wimpy", 70);
	set("icon",old_man1);
	
	set("max_hp", 1000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 80);
	set("combat_exp", 100000);
	
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("strike", 60);
	set_skill("parry", 60);
	set_skill("literate", 60);
	set_skill("tiezhang_zhangfa", 60);
	set_skill("guiyuan_tunafa", 60);
	set_skill("shuishangpiao", 60);
	
	map_skill("force", "guiyuan_tunafa");
	map_skill("strike", "tiezhang_zhangfa");
	map_skill("parry", "tiezhang_zhangfa");
	map_skill("dodge", "shuishangpiao");
	prepare_skill("strike", "tiezhang_zhangfa");
	
	create_family("���ư�", 14, "����");
/*	
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"$YEL��ǧ����ɫ�����������������ˣ����ȥ����������������ʮ���գ����ɼ��磬����С��������$COM\n",
			"$YEL��ǧ�𼱵������ٲ�ס�֣�үү�ɾ�Ҫ�������ˣ�����$COM\n",
			(: random_move :)
	}) );
*/	
	set_inquiry("����", "�ǵ��ȸ����������һ����������ô��ǧ�ߡ��������Ų�������Ҳ���ѵ�������");
	set_inquiry("����", "����������ư����̳���ڣ�����û�£���Ҫ�Ĵ����ߣ�����ɱ��֮��������");
	
    set("chat_chance", 10);
}

virtual char * chat_msg()				//NPC�Զ�����
{
	switch(random(4))
	{
	case 0:
		return 	"��ǧ�ߴ�����ֵ�˵���������ư��������µ����飬û��үү��֪���ģ���";
	case 1:
		return 	"��ǧ�����ص�˵����������������һ����Ĺ����˵���ﾭ���ֹ���";
	case 2:
		return 	"��ǧ�����ص�˵������һ���ڹ������гɣ��Ϳ��Դӻ�����ľ�в���������ˣ���";
	case 3:
		return 	"��ǧ��˵��������ָ��ڶ�ָ�ڴ�����һ�����ص����ڣ���˵���ѹʰ��������֮������";
	}	
	return 0;
}
/*
void attempt_apprentice(object me)
{
	if ((int)me->query("shen") > 0) {
		command("hehe");
		command("say ����ģ�үү������������Ĵ������С���˵�����");
		return;
	}
	command("haha");
	command("say үү���书�������������޺úø�����ѧ��׼û��");
	command("recruit " + me->query("id"));
}
int ask_qiubai()
{
	say("�������ư�ĵ�ʮ������������˵ʮ��ǰ���˰��㣬���ں�������֪�����Ǽ٣�\n");
	return 1;
}
int ask_naogui()
{
	say("��һЩ����˵�����������������ϵķ�Ĺ�У������������ٺ٣�һ����ʲô���������棡\n");
	this_player()->set_temp("marks/��1", 1);
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + 
		"���ǻ����ˣ�����������үү��ѵ��ѵ�㣡��\n");
	command("say ��Ӵ����⣬��⣬�������治���ɣ����һ�ᣬ�Ҷ���ʹ��Ҫ������\n");
	return 0;
}
*/
NPC_END;