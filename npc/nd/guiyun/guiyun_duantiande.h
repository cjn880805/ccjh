// duantiande.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_duantiande);

virtual void create()
{
	set_name("��ȱ��", "duan tiande");
	set("gender", "����");
	set("title", "���α���ָ��ʹ");
	set("age", 45);
	set("per", 15);
	set("icon", officer);
	set("long", "���Ǵ����ٰ�����ָ��ʹ��");
	set("combat_exp", 4000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  20);
        set_temp("apply/defense", 20);
	set("shen_type", -1);

	add_money(3000);
	carry_object("junfu")->wear();
}
NPC_END;
