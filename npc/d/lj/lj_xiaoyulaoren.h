//lj_xiaoyulaoren.h	Ц������
//�ز� 2002��6��1

NPC_BEGIN(CNlj_xiaoyulaoren);

void create()
{
	set_name("Ц������","xiaoyu laoren");
	set("title", "һ�β���");
	set("gender", "����");
	set("age", 53);
	set("attitude", "peaceful");
	set("icon",old_man1);
	set("per", 39);
	set("str", 40);
	set("int", 45);
	set("con", 50);
	set("dex", 60);
	
	set("max_hp", 30000);
	set("mp", 20000+random(20000));
	set("max_mp", 20000+random(20000));
	set("mp_factor", 160+random(200));

	set("combat_exp", 6500000);
	set_skill("force", 400+random(400));
	set_skill("dodge", 400+random(400));
	set_skill("parry", 400+random(400));
	set_skill("sword",400+random(400));
	set_skill("hand",400+random(400));

	set_skill("beiming_shengong",400+random(400));
	set_skill("yunlong_shou",400+random(400));
	set_skill("doggiesteps", 400+random(400));
    set_skill("ice_sword", 400+random(400));
  
	map_skill("force", "beiming_shengong");
	map_skill("dodge", "doggiesteps");
	map_skill("parry", "ice_sword");
	map_skill("sword", "ice_sword");
	map_skill("hand", "yunlong_shou");

	prepare_skill("hand", "yunlong_shou");
	carry_object("icesword")->wield();
	set("no_huan",1);
	
};

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(!who->query("lj/renwu4"))	return 0;
	if(!ob->query("xiaoyuelaoren")) return 0;
	destruct(ob);
	tell_object(who, "Ц�����˽ӹ�������ϵ����ţ�˺����ڣ������Ŀ���������");
	tell_object(who, "����֮�󣬲���һ����̾�����ˡ�����");
	tell_object(who, "ת��ͷ��������˵�����������ˣ��鷳���ȥ������һ�£��������̵ľ��£��Ͳ�Ҫ����ǣ���ˡ�");
	who->set("lj/renwu4_hueifu",1);
	return 1;
}

NPC_END;




