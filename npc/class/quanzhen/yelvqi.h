// quanzhen_yelvqi.c Ү����

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_yelvqi);

virtual void create()
{
	set_name("Ү��ƽ", "Yelv ping");
	set("title", "ȫ��̵ڶ������� ؤ��ڶ�ʮһ������");
	set("gender", "����");
	set("age", 25);
	set("per", 25);
	set("long", "�������ض��Ĵ�Ů����ܽ�õ��ɷ�");
	
	set("combat_exp", 600000);
	set("shen_type", 1);
	set("icon",begger);
	
	set("max_mp", 2000);
	set("mp", 2000);
	set("mp_factor", 0l);
	set("foolid",40);

	set_skill("force", 120);
	set_skill("sword", 120);
	set_skill("dodge", 100);
	set_skill("parry", 120);
	set_skill("unarmed",120);
	set_skill("strike",80);

	set_skill("xiantian_qigong", 120);    //��������
	set_skill("quanzhen_jian",120);  //ȫ�潣
	set_skill("jinyan_gong", 100);   //���㹦
	set_skill("haotian_zhang", 120);    //�����

	set_skill("literate",100);
	set_skill("taoism",80);
	
	create_family("ȫ���", 2, "����");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
}
NPC_END;