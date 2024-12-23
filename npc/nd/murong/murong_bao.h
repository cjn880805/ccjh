// bao.c ����ͬ
//sound 2001-07-16

NPC_BEGIN(CNmurong_bao);

virtual void create()
{
	set_name("����ͬ", "bao butong");
	set("title","���ׯׯ��");
	set("nickname","��������");
	set("long", 
		"������Ľ���ظ��Ľ���ֵܹ���Ľ�ݽ��ׯ��ׯ����\n");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 46);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("icon",young_man5);
	
	set("max_hp", 2500);
	set("hp", 1000);
	set("mp", 2500);
	set("max_mp", 2500);
	set("mp_factor", 100);
	set("combat_exp", 850000);
	set("score", 85000);
	
	set_skill("sword",130);
	set_skill("dodge",130);
	set_skill("force", 130);
	set_skill("shenyuan_gong", 130);
	set_skill("yanling_shenfa", 130);
	set_skill("parry", 130);
	set_skill("blade",150);
	set_skill("murong_daofa", 150);
	set_skill("literate", 130);
	set_skill("finger", 130);
	set_skill("canhe_zhi", 130);
	set_skill("strike", 130);
	set_skill("xingyi_zhang", 130);
	
	map_skill("force", "shenyuan_gong");
	map_skill("strike", "xingyi_zhang");
	map_skill("finger", "canhe_zhi");
	map_skill("dodge", "yanling_shenfa");
	map_skill("parry", "murong_daofa");
	map_skill("blade", "murong_daofa");  
	prepare_skill("finger", "canhe_zhi");
	prepare_skill("strike", "xingyi_zhang");
	
	
	carry_object("cloth2")->wear();
	carry_object("gangdao")->wield();   
	create_family("����Ľ��",3,"����");
	
	set_inquiry("����", "��Ҳ����Ҳ���Ҿ��ǹ���Ľ�ݽ��ׯׯׯ������ͬ��");
	set_inquiry("����", "�����Ǵ��������������룬�ѵ���û����˵����");
	set_inquiry("����", "Ľ�ݹ��ӵ��Ա�֮������ʩ��������������");
	set_inquiry("����", "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�");
	set_inquiry("����", "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����");
	set_inquiry("������", "��������Ľ�ݹ��ӵı��ã���֪��ʲôʱ�����ǳ��ס�");
	set_inquiry("��ǧ��", "�˰ٴ����Ҵ�磬������������ׯ��ׯ����");
	set_inquiry("������", "����Ǭ���Ҷ��磬���������ϼׯ��ׯ����");
	set_inquiry("�粨��", "�粨�������ĵܣ�����������˪ׯ��ׯ����������ϲ�������˴�ܡ�");
	set_inquiry("����ˮ�",  "����ˮ��ǰ������ס�ĵط��������ﲻԶ��");
	set_inquiry("����С��",  "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�");
	set_inquiry("��٢��ɽׯ", "��٢��ɽׯ�ǹ��ӵĹ���ס�ĵط���ƽʱ���Ҷ�����ȥ��");
	set_inquiry("��ʩˮ��", "���������������֮���ڣ��ҿɲ������˵��");
	
}
/*
void attempt_apprentice(object ob)
{
	command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
	command("recruit " + ob->query("id"));
	ob->set("title","����Ľ�ݵ��Ĵ�����");
}
*/
NPC_END;