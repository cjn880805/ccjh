//laocai.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_laocai);

virtual void create()
{
	set_name("�ϲ�","laocai");

	set("icon", drugstore_boss);
	set("gender", "����" );
	set("nickname","�ϲ�");
	set("age", 40);
	set("long", "һ�����������Ĺ����������տ����Ų�Ҳ�ܷ����Ƶġ�");
	set("shen_type",-1);
	set("combat_exp", 10000);
	set("str", 17);
	set("dex", 18);
	set("con", 18);
	set("int", 18);
	set("attitude", "friendly");
	carry_object("cloth")->wear();
	set_inquiry ("��" ,  inquiry_dao  );
};

static char * inquiry_dao(CNpc * this_object, CChar * this_player)
{
	CContainer * ob;
	
	if (this_player->PresentName("chaidao",IS_ITEM))
		return "�ϲĵ�����˵�������ϴ���һ�ѣ�����Ҫ��";

	ob=load_item("chaidao");
	ob->move(this_player);
	return "�ϲĵݸ���һ�Ѳ񵶣�������˵��С�ı��ܣ�";
}

NPC_END;
