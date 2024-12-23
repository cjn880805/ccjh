//beijing_waswai.h  北京万安寺外

RESIDENT_BEGIN(CRbeijing_waswai);

virtual void create()
{
	set_name( "万安寺外");
	set("resident", "北京");

	add_door("北京西南", "北京西南", "北京万安寺外");
	add_door("万安寺", "北京万安寺", "北京万安寺外");
};

RESIDENT_END;
