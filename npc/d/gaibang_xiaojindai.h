//xiaojindai.h
//code by zwb
//12-16

NPC_BEGIN(CNgaibang_xiaojindai);

virtual void create()
{
	set_name("�����","xiao jin dai");

	set("gender", "����");
	set("nickname","����ɮ");
	set("age", 28);
	set("long","������ؤ��ǰ�ΰ��������ĸ��ף�Ǳ��������ʮ���ˡ�����һ����ͨ�ĺ�ɮ�ۣ�������һ���������һϵ��������������࣬���ʮ�ֿ��࣬����һ�������ֿ���ʮ�����Ի������ӣ�˫Ŀ��磬��������");
	set("attitude", "peaceful");
 	set("icon",young_man4);
	
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	
	set("combat_exp", 180000);
	set("score", 20000);
	 
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
};


NPC_END;
