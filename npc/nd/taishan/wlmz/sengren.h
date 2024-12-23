//taishan_sengren.h
//code by sound
//2001-07-11

NPC_BEGIN(CNtaishan_shengren);

virtual void create()
{
	set_name("�η�����", "seng ren");
	set("long", "����һλ�����η����У�����������ϵ����Ĵ����˲�����");

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 45);
	set("shen_type", 1);
	set("str", 20);
	set("int", 30);
	set("con", 25);
	set("dex", 23);
	set("max_hp", 380);
	set("hp", 300);
	set("mp", 380);
	set("max_mp", 380);
	set("mp_factor", 27);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("chat_chance", 30);

	set_skill("force", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);

	setup();
	carry_object("cloth")->wear();

}

int accept_object(object me, object obj)
{
	if( obj->query("name") == "��վ�" )
	{
		command("smile");
		command("say �����ӷ𣬶�л��λ" + RANK_D->query_respect(me) + "�� ��");
		command("say ƶɮ�����Ȿ��վ�������ʯƺ�ϵ�ԭ�İ� ��");
	}

	return 1;
}

