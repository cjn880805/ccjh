// qiuqianzhang.h ��ǧ��
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_qiuqianzhang);

virtual void create()
{
	set_name("��ǧ��", "qiu qianzhang");
	set("nickname", "����ˮ����");
	set("gender", "����");
	set("age", 65);
	set("long", 
		"���и��ܵܽ���ǧ�������и����ý���ǧ�ߡ����Լ�����Ȼ�ȵܵ�\n"
		"������ǧ�ߣ������ø��Ƕ��˾�ǧ�ߣ����ϵĹ�����ȴ������ϡ����\n"
		"�پ���ߡ�\n"); 
	set("per",14);
	set("icon", old_man2);
	set("combat_exp", 50000);
	set_skill("dodge", 50);
	set_skill("lingxu_bu", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("changquan", 50);
	map_skill("dodge", "lingxu_bu");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");
	set("shen_type", -1);

//	add_money("silver",3);
	carry_object("cloth")->wear();
}

NPC_END;