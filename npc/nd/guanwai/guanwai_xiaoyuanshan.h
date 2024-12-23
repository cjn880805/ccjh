// xiaoyuanshan.c
//sound 2001-07-18

NPC_BEGIN(CNguanwai_xiaoyuanshan);

virtual void create()
{
	set_name("����ˮ", "xiao yuanshan");
	set("gender", "����");
	set("nickname","����ɮ");
	set("age", 58);
	set("long", 
		"������ؤ��ǰ�ΰ������εĸ��ף�Ǳ��������ʮ���ˡ�\n"
		"����һ����ͨ�ĺ�ɮ�ۣ�������һ���������һϵ��\n"
		"������������࣬���ʮ�ֿ��࣬����һ�������ֿ���\n"
		"ʮ�����Ի������ӣ�˫Ŀ��磬��������\n");
	set("attitude", "peaceful");
	
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("icon",old_man1);	

	set("hp", 4000);
	set("max_hp", 4000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	
	set("combat_exp", 180000);
	set("shen_type", 1);
	 
	set_skill("force", 120);             // �����ڹ�
	set_skill("hunyuan_yiqi", 120);      // ��������
	set_skill("unarmed", 120);           // ����ȭ��
	set_skill("jingang_quan", 120);      // ����ʮ����
	set_skill("dodge", 120);      	     // ��������
	set_skill("shaolin_shenfa", 120);    // ��ң��
	set_skill("parry", 120);             // �����м�
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("unarmed", "jingang_quan");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "jingang_quan");
	
	carry_object("cloth")->wear();
}

NPC_END;