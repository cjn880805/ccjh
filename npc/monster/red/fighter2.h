//Lanwood 2000-09-17

FIGHTER_BEGIN(CNwiz_fighter2);

void create()
{
	set_name("ս��", "zhan shen");

	set("title", "������Ǽ�Ա");
	set("icon", boy2);
	
	set("chname", "ս��");
	set("channel", "f2");

	set("wait_time", 10);

	set("grant", 80);
				
	set("judge/attr", "level");
	set("judge/min", 30);
	set("judge/max", 60);
	set("judge/desc", "�ȼ���30����60��֮�䣨����60������");

	set("biwu/name", "���������");
	set("biwu/register/0", "��ȱ");
	set("biwu/turn0/0", "0");

	set("file_name", querystr("base_name"));

//-------------------------------------------
		set("icon",young_man2);
	
	set("attitude", "peaceful");
	set("class", "scholar");
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("chat_chance", 10);
	set("chat_chance_combat", 15);

	set("max_hp",9000);
	set("mp", 6500);
	set("max_mp", 6500);
	set("mp_factor", 150);
	
	
	set("combat_exp", 5000000);
    
	set_skill("force", 280);             // �����ڹ�
	set_skill("claw", 200);              // ����צ��
	set_skill("hand", 220);              // �����ַ�
	set_skill("finger", 240);            // ����ָ��
    set_skill("unarmed", 280);           // ����ȭ��
    set_skill("strike", 220);            // ����ȭ��
	set_skill("leg", 220);	           // ����ȭ��
    set_skill("dodge", 280);             // ��������
    set_skill("parry", 280);             // �����м�
    set_skill("sword", 300);             // ��������

    set_skill("anying_fuxiang", 280);    // ��Ӱ����
    set_skill("tanzhi_shentong", 300);   // ��ָ��ͨ
    set_skill("xuanfeng_leg", 280);      // ����ɨҶ��
    set_skill("luoying_shenzhang", 280);     // ��Ӣ����
	set_skill("bibo_shengong", 300);     // �̲���
    set_skill("luoying_shenjian", 280);  // ��Ӣ��
    set_skill("yuxiao_jianfa", 300);       // ���｣��
    set_skill("lanhua_shou", 280);       // ������Ѩ��
    set_skill("qimen_wuxing",300);       // ��������
    set_skill("literate", 300);           // ����ʶ��
	
    map_skill("force"  , "bibo_shengong");
    map_skill("finger" , "tanzhi_shentong");
    map_skill("hand"   , "lanhua_shou");
	map_skill("unarmed", "luoying_shenzhang");
    map_skill("strike", "luoying_shenzhang");
	map_skill("leg", "xuanfeng_leg");
    map_skill("dodge"  , "anying_fuxiang");
    map_skill("parry"  , "tanzhi_shentong");
    map_skill("sword"  , "tanzhi_shentong");
	
	prepare_skill("finger", "tanzhi_shentong");
	prepare_skill("hand", "lanhua_shou");

	carry_object("bluecloth")->wear();
	carry_object("yuxiao");
//---------------------------------------------------
	Load();
};

char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("force powerup", 1);
		break;
	case 1:
		perform_action("hand fuxue", 1);
		break;
	case 2:
		perform_action("finger hui", 1);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

FIGHTER_END;




