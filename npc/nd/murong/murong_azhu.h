//  azhu.c ����
//sound 2001-07-16

NPC_BEGIN(CNmurong_azhu);

virtual void create()
{
	set_name("����", "a zhu");
	set("gender", "Ů��");
	set("age", 20);              
	set("title","����Ѿ��");
	set("str", 25);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("per", 30);
	set("icon",young_woman10);
	set("combat_exp", 14000);
	set("shen_type", 0l);
	set("attitude", "peaceful");
	set("max_hp",1000);
	set("hp",1000);
	set("mp",1000);
	set("max_mp",1000);
	set("mp_factor",30);
	set("score", 8000);
	
	set_skill("cuff", 50);
	set_skill("parry",50);
	set_skill("yanling_shenfa",50);
	set_skill("dodge", 50);
	set_skill("force",50);
	set_skill("shenyuan_gong",50);
	
	map_skill("force","shenyuan_gong");
	map_skill("dodge","yanling_shenfa");      
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	
	carry_object("shoe")->wear();
//	carry_object("red_silk")->wear();
	carry_object("skirt")->wear();
	
	set_inquiry("����", "�Ҿ���Ľ�ݹ��ӵ�����Ѿ�߰��飬�þò������Ӳ�֪����û�С�");
	set_inquiry("����", "����������ˮ鿣���Ľ����үΪ���չ��Ҹ��Ұ��ŵ�ס����");
	set_inquiry("����",  "�����һ��������������룬Ҫȥ��ʩˮ���书�ؼ�����������ѽ��");
	set_inquiry("Ľ���ظ�",  "Ľ���ظ�����������������ˣ����Ա�֮������ʩ���������������");
	set_inquiry("��ʩˮ��",  "��ֻ֪����ʩˮ���ǹ��Ӳ���ĵط����ɲ�֪������ʲô�ط���");
	set_inquiry("����", "�������ҵĺ���ü����ס������С��������һ���ǹ��ӵ�����Ѿ�ߡ�");
	set_inquiry("����", "��������������������﹩������ү�ӵ���λ����ǰ�����");
	set_inquiry("����", "������������ү�ӵ���λ��һ����ǰ�ı�������Ϊ���񽣣��������¶�Я��ٺƷ����������λǰ��");
//	set_inquiry("����" : (: ask_sword :));
}
/*
string ask_sword()
{
	mapping fam; 
//	object ob;
	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	return "��������ү�����ź��������������������úñ��ܣ��Ұ����ŵ������������ˣ�\n";
}
*/

NPC_END;