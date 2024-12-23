//xiaoyao_shanyao.h и╫яЭ
//гь╡╗ 2002║╒12║╒5

XiaoYao_BEGIN(CRXiaoYao_shanyao);

virtual void create()
{
	set_name( "и╫яЭ");

	set("monster_chance",60);
	set("no_autosave",1);

	add_door("Епрё╧хвоа╚╥Еи╫б╥1", "Епрё╧хвоа╚╥Еи╫б╥1", "Епрё╧хвоа╚╥Еи╫яЭ");
	add_door("Епрё╧хвоа╚╥Еи╫б╥2", "Епрё╧хвоа╚╥Еи╫б╥2", "Епрё╧хвоа╚╥Еи╫яЭ");

};

XiaoYao_END;
