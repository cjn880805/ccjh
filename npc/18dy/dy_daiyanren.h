//dy_daiyanren.h
//lanwood 2001-11-04

NPC_BEGIN(CNdy_daiyanren);

void create()
{
	set_name("����������", "daiyan ren");
	
	set("gender", "����");
	
	set("icon", young_woman1);
	set("level", 20);
	
	set("max_hp", 12000);
	set("max_mp", 3000);
	set("mp_factor", 70);
	
	set("combat_exp", 952800);
	
	set("cast_chance", 20);
	set("nkgain", 1);
	
	set("str", 34);
	set("con", 35);
	set("int", 35);
	set("dex", 22);
	
	set_skill("changquan", 206);
	set_skill("cuff", 206);
	set_skill("guimei_shenfa", 206);
	set_skill("dodge", 206);
	set_skill("hunyuan_yiqi", 206);
	set_skill("force", 206);
	
	map_skill("cuff", "changquan");
	map_skill("dodge", "guimei_shenfa");
	map_skill("force", "hunyuan_yiqi");
	
	prepare_skill("cuff", "changquan");
	
	set("apply/armor", 120);
	set("apply/damage", 150);

//	set("18dy/ceshi", 0l);
//	set("18dy/buxihuan", 0l);
}

int do_talk(CChar * me, char * ask = NULL)
{

	AddMenuItem("ʮ�˵���", "$018dy $1", me);
	AddMenuItem("�μӲ���", "$0ceshi $1", me);
	AddMenuItem("�Ҳ�ϲ��", "$0buxihuan $1", me);
	SendMenu(me);	

	return 1;
}

int handle_action(char *comm, CChar *me, char * arg)
{

	if(strcmp(comm, "18dy") == 0)
		return do_18dy(me);
	if(strcmp(comm, "ceshi") == 0)
		return do_ceshi(me);	
	if(strcmp(comm, "buxihuan") == 0)
		return do_buxihuan(me);

	return CNpc::handle_action(comm, me, arg);
}

int do_18dy(CChar * me)
{
		
	say("ʮ�˵�����XXͬ־����ʱ��С�����µ�һ����Ц"
		"����������ļ���ʹ����Ѳ��������˵����еĵȴ�"
		"����¶���˱�ɽһ�ǣ�������ȶ�Ϊ�졣", me);
	say("��˵����ʮ�˵������������Լ��ľ���ͼ��ܣ�"
		"�л���ȥʮ�˵������Խ����е������˶��Զ��м�����ջ�����", me);
	say("ʮ�˵�������Ѱ�������书��������䱦��"
		"ÿһ�㶼�У���85��Ϊ��Щ�����ܿ��£���ʱ�����ų�����", me);
	say("ʮ�˵Ļ�Ҫ����������"
		"����һ�������棬�ͱ�������һ������������ϰ��ѧ��"
		"��85�����޸�Ȩ��", me);
	say("������䡢�书��Ƭ����Ʒ����������������ʱ���ţ�"
		"ֱ����BUG���𲽷ų���", me);
	say("���ˣ����Ƕ������ɡ�"
		"����������������������"
		"85����", me);

	SendMenu(me);
	return 1;
}

int do_ceshi(CChar * me)
{
	
	CContainer * obj = me->PresentName("18qing_tie", IS_ITEM);
	if(! obj)
	{	
		say("�ã���������������мɲ�Ҫ��ʧ��", me);

		SendMenu(me);
		
		load_item("18qing_tie")->move(me);
		add("18dy/ceshi", 1);
		tell_object(me, "$HIY�õ�������");	
	}
	return 1;
}

int do_buxihuan(CChar * me)
{
		
	say("�Ҳ���ȥʮ�˵�����85ȥ���ɣ�", me);

	SendMenu(me);
	add("18dy/buxihuan", 1);
	return 1;
	tell_object(me, "$HIY85��......��");	

}

NPC_END;