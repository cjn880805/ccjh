//tanghua.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_tanghua);

virtual void create()
{
	set_name("���ƹ�","tanghua");
	
	set("icon", pub_boss);
	set("long","���ƹ�����Ҵ��¥�����ˣ�����ֻ��һ��СС�ľ�¥�ϰ壬�ڳɶ������ᶽ��ү���⣬���¾�������ƴ��ƴ�" );
	set("age", 46);
	set("attitude", "peaceful");
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);
	
	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	set_inquiry("����", "�������Ƶ���һ�����֡�");
	set_inquiry("����", "�˴������سǾ�¥��������Ҫ��ˣ��Ը������С��һ����ɡ�,");
	set_inquiry("�ƻ�", "���ң����±����ƻ�����֪�����кηԸ���");
	set_inquiry("�سǾ�¥", "������ǣ������ǵ�һ������");
	add_money(15);
	carry_object("cloth")->wear();
};


NPC_END;
