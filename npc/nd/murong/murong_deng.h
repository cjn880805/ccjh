// deng.c �˰ٴ�
//sound 2001-07-16

NPC_BEGIN(CNmurong_deng);

virtual void create()
{
	set_name("��ǧ��", "deng baichuan");
	set("title","����ׯׯ��");
	set("long", "�����ǹ���Ľ������ׯ��ׯ����");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 36);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("icon",young_man6);
	
	set("max_hp", 2000);
	set("hp", 2000);
	set("mp", 2500);
	set("max_mp", 2500);
	set("mp_factor", 100);
	set("combat_exp", 750000);
	set("score", 85000);
	
	set_skill("finger",130);
	set_skill("dodge",130);
	set_skill("force", 130);
	set_skill("shenyuan_gong", 130);
	set_skill("yanling_shenfa", 130);
	set_skill("parry", 130);
	set_skill("canhe_zhi", 150);
	set_skill("literate", 130);
	
	map_skill("force", "shenyuan_gong");
	map_skill("dodge", "yanling_shenfa");
	map_skill("parry", "xingyi_zhang");
	map_skill("finger", "canhe_zhi");	
	
	prepare_skill("finger","canhe_zhi");
	
	carry_object("cloth")->wear();        
	create_family("����Ľ��",3,"����");
	
	set_inquiry("����", "�Ҿ��ǹ���Ľ������ׯׯ����ǧ����");
	set_inquiry("����", "�����Ǵ��������������룬�ѵ���û����˵����");
	set_inquiry("����",  "Ľ�ݹ��ӵ��Ա�֮������ʩ��������������");
	set_inquiry("����",  "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�");
	set_inquiry("����",  "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����");
	set_inquiry("������", "��������Ľ�ݹ��ӵı��ã���֪��ʲôʱ�����ǳ��ס�");
	set_inquiry("������", "����Ǭ���Ҷ��ܣ����������ϼׯ��ׯ����");
	set_inquiry("����ͬ", "����ͬ�������ܣ�����������ׯ��ׯ����������ϲ��˵����Ҳ����Ҳ����");
	set_inquiry("�粨��", "�粨�������ĵܣ�����������˪ׯ��ׯ����������ϲ�������˴�ܡ�");
	set_inquiry("����ˮ�",  "����ˮ��ǰ������ס�ĵط��������ﲻԶ��");
	set_inquiry("����С��",  "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�");
	set_inquiry("��٢��ɽׯ", "��٢��ɽׯ�ǹ��ӵĹ���ס�ĵط���ƽʱ���Ҷ�����ȥ��");
	set_inquiry("��ʩˮ��", "���������������֮���ڣ��ҿɲ������˵��");
	
	set("chat_chance",20);
}

virtual char * chat_msg()		//NPC�Զ�����
{
	switch(random(3))
	{
	case 0:
		return 	"��ǧ���������ﵽ�����ϻض���˹��ӵĹ�Ԫ����Ҫô�ĵܵ������Ͷ��ˡ���";
	case 1:
		return 	"��ǧ����������ү��ǰ���Ӱ����Ǳ���Ҳһͬ�����ˡ�";
	case 2:
		return 	"��ǧ����������үȥ�������ҵ�ͷ��������ˡ�";
	}	
	return 0;
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