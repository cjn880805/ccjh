NPC_BEGIN(CNPub_dibao);

virtual void create()
{
	set_name("�ر�","dibao");

	set("icon", banditi);
	set("gender", "����" );
	set("age", 43);
	set("long", "�Ժ���������������������ˣ����ʱ������ȥ������һ��.���ھֵ��������֣����˵�Ǯ��������Ȣ�˷����ţ���ũΪ��.��������������������棬�ֻ�Щ�书�����������˵ر���");

    set("str", 25);
    set("dex", 20);
    set("con", 17);
    set("int", 15);
	set("shen_type", 1);

    set_skill("unarmed", 30);
	set_skill("dodge", 20);
    set_temp("apply/attack", 15);
    set_temp("apply/defense", 15);
    set("combat_exp", 2500);

	set("attitude", "peaceful");
    add_money(150);
	carry_object("cloth")->wear();
	carry_object("yaodai")->wear();

};

NPC_END;